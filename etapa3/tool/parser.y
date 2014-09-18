%{
#include <stdio.h>
#include <stdlib.h>
            
#include "../include/hash.h"
#include "../include/ast.h"
#include "../include/gv.h"

//#define YYDEBUG 1
int yydebug = 1;
int yyerror( char* str );
ast *ast_t;

extern  int getLineNumber( void );
extern  int isRunning( void );
extern  int yylex( );
       
%}
 
%union
	{
	ast*        ast;
	HASH_NODE   *symbol;
	};
 
%right	    '='
%left       OPERATOR_AND OPERATOR_OR
%nonassoc   OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE '<' '>'
%left       '+' '-'
%left	    '*' '/'
%left       KW_THEN
%left       KW_ELSE
 
%token  KW_WORD		    256
%token  KW_BOOL		    258
%token  KW_BYTE		    259
%token  KW_IF		    261
%token  KW_THEN		    262
%token  KW_ELSE		    263
%token  KW_LOOP		    264
%token  KW_INPUT	    266
%token  KW_RETURN	    267
%token  KW_OUTPUT	    268

%token  OPERATOR_LE	    270
%token  OPERATOR_GE	    271
%token  OPERATOR_EQ 	272
%token  OPERATOR_NE     273
%token  OPERATOR_AND	274
%token  OPERATOR_OR	    275
 
%token TOKEN_ERROR	    290

%token  <symbol>    SYMBOL_UNDEFINED		0
%token  <symbol>    SYMBOL_LIT_INTEGER	    1
%token  <symbol>    SYMBOL_LIT_FLOATING	    2
%token  <symbol>    SYMBOL_LIT_TRUE		    3
%token  <symbol>    SYMBOL_LIT_FALSE		4
%token  <symbol>    SYMBOL_LIT_CHAR		    5
%token  <symbol>    SYMBOL_LIT_STRING	    6
%token  <symbol>    SYMBOL_IDENTIFIER	    7  


%type   <ast>   value
%type   <ast>   commands
%type   <ast>   command
%type   <ast>   expr
%type   <ast>   data_type
%type   <ast>   program
%type   <ast>   decl_var
%type   <ast>   decl_array
%type   <ast>   decl_global
%type   <ast>   decl_local
%type   <ast>   decl_func
%type   <ast>   flux_control
%type   <ast>   block
%type   <ast>   parameters
%type   <ast>   output
%type   <ast>   param_func
%type   <ast>   vetor_value

%start program_ini

%%
 
program_ini:    program		                                                            { astPrintTree ($1,0); }       
		        ;

program:	    program decl_global                                                     { $$ = astCreate(AST_LIST_VAR,0,$1,$2,0,0); }
		        |                                                                       { $$ = 0; }
		        ;
 
decl_global:    decl_var ';'                                                            { $$ = $1; }
		        | decl_array ';'                                                        { $$ = $1; }
		        | decl_func                                                             { $$ = $1; }
		        ;
 
decl_var:	      data_type SYMBOL_IDENTIFIER ':' value                                 { $$ = astCreate(AST_VAR,$2,$1,$4,0,0); }
		        ;
 
decl_array:	    data_type SYMBOL_IDENTIFIER '[' expr ']'                                { $$ = astCreate(AST_VECTOR,$2,$1,$4,0,0); }
		        | data_type SYMBOL_IDENTIFIER '[' expr ']' ':' vetor_value              { $$ = astCreate(AST_VECTOR,$2,$1,$4,$7,0); }
		        | data_type '$' SYMBOL_IDENTIFIER                                       { $$ = astCreate(AST_PONT,$3,$1,0,0,0); }
		        | data_type '$' SYMBOL_IDENTIFIER ':' value                             { $$ = astCreate(AST_PONT,$3,$1,$5,0,0); }
		        ;
 
decl_local:	    decl_var                                                                { $$ = $1; }
		        | decl_var ';' decl_local                                               { $$ = $1; }
		        |                                                                       { $$ = 0; }
		        ;
 
vetor_value:    value                                                                   { $$ = $1; }
		        | value vetor_value                                                     { $$ = $1; }
		        ;
 
decl_func:	    data_type SYMBOL_IDENTIFIER '(' parameters ')' block                    { $$ = astCreate(AST_DEC_FUNC,$2,$1,$4,$6,0); }
                | data_type SYMBOL_IDENTIFIER '(' parameters ')' decl_local block       { $$ = astCreate(AST_DEC_FUNC,$2,$1,$4,$6,$7); }
		        | data_type SYMBOL_IDENTIFIER '(' parameters ')' decl_local commands    { $$ = astCreate(AST_DEC_FUNC,$2,$1,$4,$6,$7); }
		        ;
 
parameters:	    data_type SYMBOL_IDENTIFIER                                             { $$ = astCreate(AST_PRM_DEC_FUNC,$2,$1,0,0,0); }
	    	    | data_type SYMBOL_IDENTIFIER ',' parameters                            { $$ = astCreate(AST_PRM_DEC_FUNC_LIST,$2,$1,$4,0,0); }
	    	    |                                                                       { $$ = 0; }
	    	    ;
 
block:		    '{' commands '}' ';'                                                    { $$ = astCreate(AST_CMD_BLCK,0,$2,0,0,0); }
                ;
 
commands:	    command ';' commands                                                    { $$ = astCreate(AST_CMD_LIST,0,$1,$3,0,0); }
		        | command                                                               { $$ = astCreate(AST_CMD,0,$1,0,0,0); }
		        | block commands                                                        { $$ = astCreate(AST_CMD_LIST,0,$1,$2,0,0); }
                |                                                                       { $$ = 0; }
		        ;
 
command:        SYMBOL_IDENTIFIER '=' expr                                              { $$ = astCreate(AST_EQUAL,$1,$3,0,0,0); }
		        | SYMBOL_IDENTIFIER '[' expr ']' '=' expr                               { $$ = astCreate(AST_EQUAL_VEC,$1,$3,$6,0,0); }
		        | KW_OUTPUT output                                                      { $$ = astCreate(AST_OUTPUT,0,$2,0,0,0); }
		        | KW_INPUT SYMBOL_IDENTIFIER                                            { $$ = astCreate(AST_INPUT,$2,0,0,0,0); }
		        | KW_RETURN expr                                                        { $$ = astCreate(AST_RETURN,0,$2,0,0,0); }
		        | flux_control                                                          { $$ = $1; }
		        | block                                                                 { $$ = $1; }
		        |                                                                       { $$ = 0; }
		        ;
 
output:         expr                                                                    { $$ = astCreate(AST_SINGLE_OUTPUT,0,$1,0,0,0); }
		        | output ',' expr                                                       { $$ = astCreate(AST_LIST_OUTPUT,0,$1,$3,0,0); }
		        ;
			
flux_control:	KW_IF expr KW_LOOP commands                                             { $$ = astCreate(AST_LOOP,0,$2,$4,0,0); }
		        | KW_IF expr KW_THEN commands                                           { $$ = astCreate(AST_IF,0,$2,$4,0,0); }
		        | KW_IF expr KW_THEN commands KW_ELSE commands                          { $$ = astCreate(AST_IF_ELSE,0,$2,$4,$6,0); }
		        | KW_IF expr KW_ELSE commands                                           { $$ = astCreate(AST_ELSE,0,$2,$4,0,0); }
		        ;
 
expr:		    SYMBOL_IDENTIFIER                                                       { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
		        | SYMBOL_IDENTIFIER '[' expr ']'                                        { $$ = astCreate(AST_VECTOR_ID,$1,$3,0,0,0); }
		        | SYMBOL_IDENTIFIER '(' param_func ')'  								{ $$ = astCreate(AST_FUNC_CALL,$1,$3,0,0,0); }	
		        | value                                 								{ $$ = $1; }
		        | '(' expr ')'                          								{ $$ = $2; }
		        | expr '+' expr				            								{ $$ = astCreate(AST_ADD,0,$1,$3,0,0); }
		        | expr '-' expr				            								{ $$ = astCreate(AST_SUB,0,$1,$3,0,0); }
		        | expr '*' expr				            								{ $$ = astCreate(AST_MUL,0,$1,$3,0,0); }
		        | expr '/' expr				            								{ $$ = astCreate(AST_DIV,0,$1,$3,0,0); }
		        | expr OPERATOR_AND expr	        									{ $$ = astCreate(AST_OP_AND,0,$1,$3,0,0); }
		        | expr OPERATOR_OR expr		        									{ $$ = astCreate(AST_OP_OR,0,$1,$3,0,0); }
		        | expr OPERATOR_LE expr		        									{ $$ = astCreate(AST_OP_LE,0,$1,$3,0,0); }
		        | expr OPERATOR_GE expr		        									{ $$ = astCreate(AST_OP_GE,0,$1,$3,0,0); }
		        | expr OPERATOR_EQ expr		        									{ $$ = astCreate(AST_OP_EQ,0,$1,$3,0,0); }
		        | expr OPERATOR_NE expr		        									{ $$ = astCreate(AST_OP_NE,0,$1,$3,0,0); }
		        | expr '<' expr				            								{ $$ = astCreate(AST_LESS,0,$1,$3,0,0); }
		        | expr '>' expr				            								{ $$ = astCreate(AST_GREAT,0,$1,$3,0,0); }
		        | '*' SYMBOL_IDENTIFIER	                								{ $$ = astCreate(AST_PONT_VAL,$2,0,0,0,0); }
		        | '&' SYMBOL_IDENTIFIER                 								{ $$ = astCreate(AST_PONT_END,$2,0,0,0,0); }
		        ;
 
param_func:	    SYMBOL_IDENTIFIER                   								    { $$ = astCreate(AST_PRM_FUNC_ID,$1,0,0,0,0); }
		        | param_func ',' SYMBOL_IDENTIFIER       								{ $$ = astCreate(AST_PRM_FUNC_IDLIST,$3,$1,0,0,0); }
		        | param_func ',' value                   								{ $$ = astCreate(AST_PRM_FUNC_VALUE_LIST,0,$1,$3,0,0); }
		        | value                                 								{ $$ = astCreate(AST_PRM_FUNC_VALUE,0,$1,0,0,0); }
		        |                                       								{ $$ = 0; }
		        ;	
 
data_type:	    KW_WORD     														    { $$ = astCreate(AST_KW_WORD,0,0,0,0,0); }
		        | KW_BYTE       														{ $$ = astCreate(AST_KW_BYTE,0,0,0,0,0); }
		        | KW_BOOL       														{ $$ = astCreate(AST_KW_BOOL,0,0,0,0,0); }
		        ;
 
value:		    SYMBOL_LIT_INTEGER  												    { $$ = astCreate(AST_LIT_INTEGER,$1,0,0,0,0); }
		        | SYMBOL_LIT_CHAR       												{ $$ = astCreate(AST_LIT_CHAR,$1,0,0,0,0); }
		        | SYMBOL_LIT_STRING     												{ $$ = astCreate(AST_LIT_STRING,$1,0,0,0,0); }
		        | SYMBOL_LIT_TRUE       												{ $$ = astCreate(AST_LIT_TRUE,$1,0,0,0,0); }
		        | SYMBOL_LIT_FALSE      												{ $$ = astCreate(AST_LIT_FALSE,$1,0,0,0,0); }
		        ;
 
%%
 
 
int yyerror(char* str)
{
	fflush(stderr);
	fprintf(stderr,"ERRO: \"%s\"\t Linha: %d\n",str,getLineNumber());
	exit(3);
 
	//fprintf(stderr,"syntax error. \n");
	//exit(3);
 
}
