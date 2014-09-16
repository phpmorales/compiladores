%{
#include <stdio.h>
#include <stdlib.h>
#include "../include/hash.h"
#include "../include/astree.h"

//#define YYDEBUG 1
int yydebug = 1;
 

extern int getLineNumber(void);
extern int isRunning(void);

int yyerror(char* str);
extern int yylex();

 
%}
 
%union
	{
	ASTREE* astree;
	HASH_NODE *symbol;
	};
 
%right	'='
%left OPERATOR_AND OPERATOR_OR
%nonassoc OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE '<' '>'
%left	'+' '-'
%left	'*' '/'
%left KW_THEN
%left KW_ELSE
 
%token KW_WORD		256
%token KW_BOOL		258
%token KW_BYTE		259
%token KW_IF		261
%token KW_THEN		262
%token KW_ELSE		263
%token KW_LOOP		264
%token KW_INPUT		266
%token KW_RETURN	267
%token KW_OUTPUT	268
 
%token OPERATOR_LE	270
%token OPERATOR_GE	271
%token OPERATOR_EQ	272
%token OPERATOR_NE	273
%token OPERATOR_AND	274
%token OPERATOR_OR	275
 
%token TOKEN_ERROR	290

%token<symbol> SYMBOL_UNDEFINED		0
%token<symbol> SYMBOL_LIT_INTEGER	1
%token<symbol> SYMBOL_LIT_FLOATING	2
%token<symbol> SYMBOL_LIT_TRUE		3
%token<symbol> SYMBOL_LIT_FALSE		4
%token<symbol> SYMBOL_LIT_CHAR		5
%token<symbol> SYMBOL_LIT_STRING	6
%token<symbol> SYMBOL_IDENTIFIER	7  


%type<astree> value
%type<astree> commands
%type<astree> command
%type<astree> expr
%type<astree> data_type
%type<astree> program
%type<astree> decl_var
%type<astree> decl_array
%type<astree> decl_global
%type<astree> decl_local
%type<astree> decl_func
%type<astree> flux_control
%type<astree> block
%type<astree> parameters
%type<astree> output
%type<astree> param_func
%type<astree> vetor_value

%start program_ini

%%

program_ini:	program		        { astreePrintTree ($1,0); }
		;

program:	decl_global program	{ $$ = AstreeCreate(ASTREE_LIST_VAR,0,$1,$2,0,0); }
		| 		        { $$ = 0; }
		;

decl_global:	  decl_var ';'          { $$ = $1; }
		| decl_array ';'        { $$ = $1; }
		| decl_func             { $$ = $1; }
		;
 
decl_var:	  data_type SYMBOL_IDENTIFIER ':' value { $$ = AstreeCreate(ASTREE_VAR,$2,$1,$4,0,0); }
		;
 
decl_array:	  data_type SYMBOL_IDENTIFIER '[' expr ']'                        { $$ = AstreeCreate(ASTREE_VECTOR,$2,$1,$4,0,0); }
		| data_type SYMBOL_IDENTIFIER '[' expr ']' ':' vetor_value      { $$ = AstreeCreate(ASTREE_VECTOR,$2,$1,$4,$7,0); }
		| data_type '$' SYMBOL_IDENTIFIER				{ $$ = AstreeCreate(ASTREE_PONT,$3,$1,0,0,0); }
		| data_type '$' SYMBOL_IDENTIFIER ':' value			{ $$ = AstreeCreate(ASTREE_PONT,$3,$1,$5,0,0); }
		;
 
decl_local:	  decl_var			{ $$ = $1; }
		| decl_var ';' decl_local  	{ $$ = $1; }
		|				{ $$ = 0; }
		;
 
vetor_value:	  value 		{ $$ = $1; }
		| value vetor_value 	{ $$ = $1; }
		;
 
decl_func:	  data_type SYMBOL_IDENTIFIER '(' parameters ')' decl_local block		{ $$ = AstreeCreate(ASTREE_DECFUNC,$2,$1,$4,$6,$7); }
		;
 
parameters:	  data_type SYMBOL_IDENTIFIER			{ $$ = AstreeCreate(ASTREE_PARAM_DECFUNC,$2,$1,0,0,0); }
		| data_type SYMBOL_IDENTIFIER ',' parameters	{ $$ = AstreeCreate(ASTREE_PARAM_DECFUNC_LIST,$2,$1,$4,0,0); }
		|						{ $$ = 0; }
		;
 
block:		'{' commands '}' ';'	{ $$ = AstreeCreate(ASTREE_COMANDBLK,0,$2,0,0,0); }
		| '{' '}' ';'		{ $$ = 0; }
		;
 
commands:	| command 		{ $$ = AstreeCreate(ASTREE_COMANDLIST,0,$1,0,0,0); }
		| command ';' commands	{ $$ = AstreeCreate(ASTREE_COMANDLIST,0,$1,$3,0,0); }	
		| block commands 	{ $$ = AstreeCreate(ASTREE_COMANDLIST,0,$1,$2,0,0); }
		|			{ $$ = 0; }
		;
 
command:	  SYMBOL_IDENTIFIER '=' expr			{ $$ = AstreeCreate(ASTREE_EQUAL,$1,$3,0,0,0); }
		| SYMBOL_IDENTIFIER '[' expr ']' '=' expr	{ $$ = AstreeCreate(ASTREE_EQUAL_VEC,$1,$3,$6,0,0); }
		| KW_OUTPUT output				{ $$ = AstreeCreate(ASTREE_OUTPUT,0,$2,0,0,0); }
		| KW_INPUT SYMBOL_IDENTIFIER
		| KW_RETURN expr
		| flux_control
		| block
		|
		;
 
output: 	  expr			{ $$ = AstreeCreate(ASTREE_SINGLE_OUTPUT,0,$1,0, 0, 0); }
		| expr ',' output  	{ $$ = AstreeCreate(ASTREE_LIST_OUTPUT,0,$1,$3,0,0); }
		;
			
flux_control:	  KW_IF expr KW_LOOP commands 			{ $$ = AstreeCreate(ASTREE_LOOP,0,$2,$4,0,0); }
		| KW_IF expr KW_THEN commands 			{ $$ = AstreeCreate(ASTREE_IF,0,$2,$4,0,0); }
		| KW_IF expr KW_THEN commands KW_ELSE commands 	{ $$ = AstreeCreate(ASTREE_IF_ELSE,0,$2,$4,$6,0); }
		| KW_IF expr KW_ELSE commands 			{ $$ = AstreeCreate(ASTREE_ELSE,0,$2,$4,0,0); }
		;
 
expr:		  SYMBOL_IDENTIFIER
		| SYMBOL_IDENTIFIER '[' expr ']'
		| SYMBOL_IDENTIFIER '(' param_func ')'
		| value
		| '(' expr ')'
		| expr '+' expr
		| expr '-' expr
		| expr '*' expr
		| expr '/' expr
		| expr OPERATOR_AND expr
		| expr OPERATOR_OR expr
		| expr OPERATOR_LE expr
		| expr OPERATOR_GE expr
		| expr OPERATOR_EQ expr
		| expr OPERATOR_NE expr
		| expr '<' expr
		| expr '>' expr
		| '*' SYMBOL_IDENTIFIER	
		| '&' SYMBOL_IDENTIFIER
		;
 
param_func:	  SYMBOL_IDENTIFIER
		| SYMBOL_IDENTIFIER ',' param_func
		| value
		| value ',' param_func
		|
		;	
 
data_type:	  KW_WORD
		| KW_BYTE
		| KW_BOOL
		;
 
value:		  SYMBOL_LIT_INTEGER
		| SYMBOL_LIT_TRUE
		| SYMBOL_LIT_FALSE
		| SYMBOL_LIT_CHAR
		| SYMBOL_LIT_STRING
		;
 
%%
 
 
int yyerror(char* str)
{
	fflush(stderr);
	fprintf(stderr,"ERRO: \"%s\"\t Linha: %d\n", str, getLineNumber());
	exit(3);
 
	//fprintf(stderr, "syntax error. \n");
	//exit(3);
 
}
