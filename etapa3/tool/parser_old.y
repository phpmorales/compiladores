%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

extern int getLineNumber(void);

%}

%union
	{
	ASTREE* astree;
	HASH_NODE* symbol;
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

%token <symbol> UNDEFINED       0
%token <symbol> TK_IDENTIFIER   1
%token <symbol> LIT_INTEGER     2
%token <symbol> LIT_FALSE       3
%token <symbol> LIT_TRUE        4
%token <symbol> LIT_CHAR        5
%token <symbol> LIT_STRING      6

%token TOKEN_ERROR		290

%type <astree> value
%type <astree> comands
%type <astree> comand
%type <astree> expr
%type <astree> data_type
%type <astree> program
%type <astree> var_dec
%type <astree> vetor_dec
%type <astree> gl_dec
%type <astree> local_dec
%type <astree> func_dec
%type <astree> flux_control
%type <astree> block_ctrl
%type <astree> block
%type <astree> parameters
%type <astree> output
%type <astree> func_param
%type <astree> vetor_value

%start program_ini

%%

program_ini:	program		{ astreePrintTree ($1,0); }
		;

program:	program	gl_dec 	{ $$ = AstreeCreate(ASTREE_LIST_VAR,0,$1,$2,0,0); }
		| 		{ $$ = 0; }
		;

gl_dec:		var_dec ';' 	{ $$ = $1; }	
		| vetor_dec ';' { $$ = $1; }		
		| func_dec 	{ $$ = $1; }	
		;

var_dec		: data_type TK_IDENTIFIER ':' value		 { $$ = AstreeCreate(ASTREE_VAR,$2,$1,$4,0,0); }
		;

vetor_dec	: data_type TK_IDENTIFIER '[' expr ']' 			{ $$ = AstreeCreate(ASTREE_VECTOR,$2,$1,$4,0,0); }
		| data_type TK_IDENTIFIER '[' expr ']' ':' vetor_value   	{ $$ = AstreeCreate(ASTREE_VECTOR,$2,$1,$4,$7,0); }
		| data_type '$' TK_IDENTIFIER 					{ $$ = AstreeCreate(ASTREE_PONT,$3,$1,0,0,0); }
		| data_type '$' TK_IDENTIFIER ':' value				{ $$ = AstreeCreate(ASTREE_PONT,$3,$1,$5,0,0); }
		;

local_dec:	var_dec 			{ $$ = $1; }
		| var_dec ';' local_dec 	{ $$ = $1; }
		| 				{ $$ = 0; }
		;

vetor_value:	value  			{ $$ = $1; }
		| value vetor_value  	{ $$ = $1; }
		;

func_dec:	data_type TK_IDENTIFIER '(' parameters ')' local_dec block 	{ $$ = AstreeCreate(ASTREE_DECFUNC,$2,$1,$4,$6,$7); }
		;

parameters:	data_type TK_IDENTIFIER				{ $$ = AstreeCreate(ASTREE_PARAM_DECFUNC,$2,$1,0,0,0); }
		| data_type TK_IDENTIFIER ',' parameters	{ $$ = AstreeCreate(ASTREE_PARAM_DECFUNC_LIST,$2,$1,$4,0,0); }
		|						{ $$ = 0; }
		;

block:		'{' comands '}' 	{ $$ = AstreeCreate(ASTREE_COMANDBLK,0,$2,0,0,0); }
		;

comands: comand ';' comands 		{ $$ = AstreeCreate(ASTREE_COMANDLIST,0,$1,$3,0,0); }
		| 				{ $$ = 0; }
		;

block_ctrl: comand 	{ $$ = $1; } 
		;

comand:		TK_IDENTIFIER '=' expr 				{ $$ = AstreeCreate(ASTREE_EQUAL,$1,$3,0,0,0); }
		| TK_IDENTIFIER '[' expr ']' '=' expr 		{ $$ = AstreeCreate(ASTREE_EQUAL_VEC,$1,$3,$6,0,0); }
		| KW_OUTPUT output  				{ $$ = AstreeCreate(ASTREE_OUTPUT,0,$2,0,0,0); }
		| KW_INPUT TK_IDENTIFIER  			{ $$ = AstreeCreate(ASTREE_INPUT,$2,0,0,0,0); }
		| KW_RETURN expr  				{ $$ = AstreeCreate(ASTREE_RETURN,0,$2,0,0,0); }
		| flux_control 					{ $$ = $1; }
		| block						{ $$ = $1; }
		;

output: 	expr		  				{ $$ = AstreeCreate(ASTREE_SINGLE_OUTPUT,0,$1,0, 0, 0); }
		| expr ',' output 				{ $$ = AstreeCreate(ASTREE_LIST_OUTPUT,0,$1,$3,0,0); }
		;
				
flux_control:	KW_LOOP '(' expr ')' block_ctrl					{ $$ = AstreeCreate(ASTREE_LOOP,0,$3,$5,0,0); }
		| KW_IF '(' expr ')' KW_THEN block_ctrl 			{ $$ = AstreeCreate(ASTREE_IF,0,$3,$6,0,0); }
		| KW_IF '(' expr ')' KW_THEN block_ctrl KW_ELSE block_ctrl	{ $$ = AstreeCreate(ASTREE_IF_ELSE,0,$3,$6,$8,0); }
		;

expr:		TK_IDENTIFIER					{ $$ = AstreeCreate(ASTREE_SYMBOL,$1,0,0,0,0); }
		| TK_IDENTIFIER '[' expr ']'		        { $$ = AstreeCreate(ASTREE_VECTOR_ID,$1,$3,0,0,0); }
		| TK_IDENTIFIER '(' func_param ')'		{ $$ = AstreeCreate(ASTREE_FUNC_CALL,$1,$3,0,0,0); }	
		| value						{ $$ = $1; }
		| '(' expr ')'					{ $$ = $2; }
		| expr '+' expr					{ $$ = AstreeCreate(ASTREE_ADD,0,$1,$3,0,0); }
		| expr '-' expr					{ $$ = AstreeCreate(ASTREE_SUB,0,$1,$3,0,0); }
		| expr '*' expr					{ $$ = AstreeCreate(ASTREE_MUL,0,$1,$3,0,0); }
		| expr '/' expr					{ $$ = AstreeCreate(ASTREE_DIV,0,$1,$3,0,0); }
		| expr OPERATOR_AND expr			{ $$ = AstreeCreate(ASTREE_OP_AND,0,$1,$3,0,0); }
		| expr OPERATOR_OR expr				{ $$ = AstreeCreate(ASTREE_OP_OR,0,$1,$3,0,0); }
		| expr OPERATOR_LE expr				{ $$ = AstreeCreate(ASTREE_OP_LE,0,$1,$3,0,0); }
		| expr OPERATOR_GE expr				{ $$ = AstreeCreate(ASTREE_OP_GE,0,$1,$3,0,0); }
		| expr OPERATOR_EQ expr				{ $$ = AstreeCreate(ASTREE_OP_EQ,0,$1,$3,0,0); }
		| expr OPERATOR_NE expr				{ $$ = AstreeCreate(ASTREE_OP_NE,0,$1,$3,0,0); }
		| expr '<' expr					{ $$ = AstreeCreate(ASTREE_LESS,0,$1,$3,0,0); }
		| expr '>' expr					{ $$ = AstreeCreate(ASTREE_GREAT,0,$1,$3,0,0); }
		| '*' TK_IDENTIFIER				{ $$ = AstreeCreate(ASTREE_PONT_VAL,$2,0,0,0,0); }
		| '&' TK_IDENTIFIER				{ $$ = AstreeCreate(ASTREE_PONT_END,$2,0,0,0,0); }
		;

func_param:	TK_IDENTIFIER 			{ $$ = AstreeCreate(ASTREE_PARAM_FUNC_ID,$1,0,0,0,0); }
		| TK_IDENTIFIER ',' func_param  { $$ = AstreeCreate(ASTREE_PARAM_FUNC_IDLIST,$1,$3,0,0,0); }
		| value 			{ $$ = AstreeCreate(ASTREE_PARAM_FUNC_VALUE,0,$1,0,0,0); }
		| value ',' func_param  	{ $$ = AstreeCreate(ASTREE_PARAM_FUNC_VALUELIST,0,$1,$3,0,0); }
		|				{ $$ = 0; }
		;	

data_type:	KW_WORD		 { $$ = AstreeCreate(ASTREE_KW_WORD,0,0,0,0,0); }
		| KW_BYTE	 { $$ = AstreeCreate(ASTREE_KW_BYTE,0,0,0,0,0); }
		| KW_BOOL	 { $$ = AstreeCreate(ASTREE_KW_BOOL,0,0,0,0,0); }
		;

value:		LIT_INTEGER	{ $$ = AstreeCreate(ASTREE_LIT_INTEGER,$1,0,0,0,0); }
		| LIT_TRUE	{ $$ = AstreeCreate(ASTREE_LIT_TRUE,$1,0,0,0,0); }
		| LIT_FALSE	{ $$ = AstreeCreate(ASTREE_LIT_FALSE,$1,0,0,0,0); }
		| LIT_CHAR	{ $$ = AstreeCreate(ASTREE_LIT_CHAR,$1,0,0,0,0); }
		| LIT_STRING	{ $$ = AstreeCreate(ASTREE_LIT_STRING,$1,0,0,0,0); }
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
