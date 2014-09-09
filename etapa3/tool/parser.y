%{
#include <stdio.h>
#include <stdlib.h>
#include "../include/hash.h"
#include "../include/astree.h"

//#define YYDEBUG 1
int yydebug = 1;
 
extern int getLineNumber(void);
extern int isRunning(void);
 
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
 
%token<symbol> SYMBOL_UNDEFINED		0
%token<symbol> SYMBOL_LIT_INTEGER	1
%token<symbol> SYMBOL_LIT_FLOATING	2
%token<symbol> SYMBOL_LIT_TRUE		3
%token<symbol> SYMBOL_LIT_FALSE		4
%token<symbol> SYMBOL_LIT_CHAR		5
%token<symbol> SYMBOL_LIT_STRING	6
%token<symbol> SYMBOL_IDENTIFIER	7
 
%token TOKEN_ERROR		290
 
   
 
%%
 
program:	decl_global program
		|
		;
 
decl_global:	decl_var ';'
		| decl_array ';'
		| decl_func
		;
 
decl_var:	data_type SYMBOL_IDENTIFIER ':' value
		;
 
decl_array:	data_type SYMBOL_IDENTIFIER '[' expr ']'
		| data_type SYMBOL_IDENTIFIER '[' expr ']' ':' vetor_value
		| data_type '$' SYMBOL_IDENTIFIER
		| data_type '$' SYMBOL_IDENTIFIER ':' value
		;
 
decl_local:	decl_var
		| decl_var ';' decl_local
		|
		;
 
vetor_value:	value 
		| value vetor_value 
		;
 
decl_func:	data_type SYMBOL_IDENTIFIER '(' parameters ')' decl_local block
		| data_type SYMBOL_IDENTIFIER '(' parameters ')' decl_local commands
		;
 
parameters:	data_type SYMBOL_IDENTIFIER
		| data_type SYMBOL_IDENTIFIER ',' parameters
		|
		;
 
block:		'{' commands '}' ';'
		| '{' '}' ';'
		;
 
commands:	| command 
		| command ';' commands		
		| block commands
		;
 
command:	SYMBOL_IDENTIFIER '=' expr
		| SYMBOL_IDENTIFIER '[' expr ']' '=' expr
		| KW_OUTPUT output
		| KW_INPUT SYMBOL_IDENTIFIER
		| KW_RETURN expr
		| flux_control
		| block
		|
		;
 
output: 	expr
		| expr ',' output
		;
			
flux_control:	KW_IF expr KW_LOOP commands
		| KW_IF expr KW_LOOP commands
		| KW_IF expr KW_THEN commands
		| KW_IF expr KW_THEN commands KW_ELSE commands
		| KW_IF expr KW_ELSE commands
		;
 
expr:		SYMBOL_IDENTIFIER
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
 
param_func:	SYMBOL_IDENTIFIER
		| SYMBOL_IDENTIFIER ',' param_func
		| value
		| value ',' param_func
		|
		;	
 
data_type:	KW_WORD
		| KW_BYTE
		| KW_BOOL
		;
 
value:		SYMBOL_LIT_INTEGER
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
