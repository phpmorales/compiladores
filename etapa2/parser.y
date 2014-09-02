%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


extern int getLineNumber(void);

%}

%union
	{
	HASH_NODE* symbol;
	};

%right	'='
%left OPERATOR_AND OPERATOR_OR
%nonassoc OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE '<' '>'
%left	'+' '-'
%left	'*' '/'

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

%token<symbol> UNDEFINED		0
%token<symbol> TK_IDENTIFIER		1
%token<symbol> LIT_INTEGER		2
%token<symbol> LIT_FALSE		3
%token<symbol> LIT_TRUE			4
%token<symbol> LIT_CHAR			5
%token<symbol> LIT_STRING		6

%token TOKEN_ERROR		290

   

%%

program:	gl_dec program
		|
		;

gl_dec:		var_dec ';'
		| vetor_dec ';'
		| func_dec
		;

var_dec:	data_type TK_IDENTIFIER ':' value
		;

vetor_dec:	data_type TK_IDENTIFIER '[' expr ']'
		| data_type TK_IDENTIFIER '[' expr ']' ':' vetor_value
		| data_type '$' TK_IDENTIFIER
		| data_type '$' TK_IDENTIFIER ':' value
		;

local_dec:	var_dec
		| var_dec ';' local_dec
		|
		;

vetor_value:	value 
		| value vetor_value 
		;

func_dec:	data_type TK_IDENTIFIER '(' parameters ')' local_dec block
		;

parameters:	data_type TK_IDENTIFIER
		| data_type TK_IDENTIFIER ',' parameters
		|
		;

block:		'{' comands '}'
		;

comands:	comand ';' comands
		| 
		;

block_ctrl:	comand
		;

comand:		TK_IDENTIFIER '=' expr
		| TK_IDENTIFIER '[' expr ']' '=' expr
		| KW_OUTPUT output
		| KW_INPUT TK_IDENTIFIER
		| KW_RETURN expr
		| flux_control
		| block
		;

output: 	expr
		| expr ',' output
		;
			
flux_control:	KW_LOOP '(' expr ')' block_ctrl
		| KW_IF '(' expr ')' KW_THEN block_ctrl
		| KW_IF '(' expr ')' KW_THEN block_ctrl KW_ELSE block_ctrl
		;

expr:		TK_IDENTIFIER
		| TK_IDENTIFIER '[' expr ']'
		| TK_IDENTIFIER '(' func_param ')'
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
		| '*' TK_IDENTIFIER	
		| '&' TK_IDENTIFIER
		;

func_param:	TK_IDENTIFIER
		| TK_IDENTIFIER ',' func_param
		| value
		| value ',' func_param
		|
		;	

data_type:	KW_WORD
		| KW_BYTE
		| KW_BOOL
		;

value:		LIT_INTEGER
		| LIT_TRUE
		| LIT_FALSE
		| LIT_CHAR
		| LIT_STRING
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
