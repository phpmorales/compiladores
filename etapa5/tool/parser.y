/*
 *
 * Author: Miller Biazus
 *		   Pedro Henrique Pinto Morales
 * UFRGS - Instituto de Informática
 * Etapa 4 - Compiladores - Prof. Marcelo de Oliveira Johann
 * 2014/2
 *
 */

%{
#include <stdio.h>
#include <stdlib.h>

#include "../include/gv.h"      
#include "../include/tac.h"  
#include "../include/semantic.h"           
#include "../include/ast.h"
#include "../include/hash.h"

//#define YYDEBUG 1
int yyerror( char* str );
ast_t *ast;
ast_t *root;
tac_t *tac;

extern int getLineNumber( void );
extern int isRunning( void );
extern int yylex( );
       
%}
 
%union
	{
	ast_t*   ast;
	hash_t   *symbol;
	};
 
%right	    '='
%left       OPERATOR_AND 
%left       OPERATOR_OR
%left       '+' 
%left       '-' 
%left	    '*' 
%left       '/' 
%left       KW_THEN
%left       KW_ELSE
%nonassoc   OPERATOR_LE     
%nonassoc   OPERATOR_GE 
%nonassoc   OPERATOR_EQ 
%nonassoc   OPERATOR_NE
%nonassoc   '<' 
%nonassoc   '>'

%token      KW_WORD		    256
%token      KW_BOOL		    258
%token      KW_BYTE		    259
%token      KW_IF		    261
%token      KW_THEN		    262
%token      KW_ELSE		    263
%token      KW_LOOP		    264
%token      KW_INPUT	    266
%token      KW_RETURN	    267
%token      KW_OUTPUT	    268

%token      OPERATOR_LE	    270
%token      OPERATOR_GE	    271
%token      OPERATOR_EQ 	272
%token      OPERATOR_NE     273
%token      OPERATOR_AND	274
%token      OPERATOR_OR	    275
 
%token      TOKEN_ERROR	    290

%token      <symbol>        UNDEFINED		0
%token      <symbol>        LIT_INTEGER	    1
%token      <symbol>        LIT_FLOATING	2
%token      <symbol>        LIT_TRUE		3
%token      <symbol>        LIT_FALSE		4
%token      <symbol>        LIT_CHAR		5
%token      <symbol>        LIT_STRING	    6
%token      <symbol>        IDENTIFIER	    7  

%type       <ast>           prg_ini
%type       <ast>           prg
%type       <ast>           dcl_vr
%type       <ast>           decl
%type       <ast>           decl_cnt
%type       <ast>           decl_type
%type       <ast>           dcl_std
%type       <ast>           dcl_ptr
%type       <ast>           dcl_arr
%type       <ast>           atrr_dcl_arr
%type       <ast>           vr_lt
%type       <ast>           dcl_fn
%type       <ast>           dcl_t_fn
%type       <ast>           prm_lst
%type       <ast>           prm_lst_cnt
%type       <ast>           blck
%type       <ast>           cmd_lst
%type       <ast>           cmd
%type       <ast>           cmd_cnt
%type       <ast>           in
%type       <ast>           atrr
%type       <ast>           ot
%type       <ast>           ot_arg
%type       <ast>           ot_arg_cnt
%type       <ast>           if
%type       <ast>           if_cmd
%type       <ast>           rtn
%type       <ast>           arr
%type       <ast>           expr
%type       <ast>           inv
%type       <ast>           lst_vl
%type       <ast>           prm
%type       <ast>           prms
%type       <ast>           vl
%type       <ast>           dt_tp

%start      prg_ini

%%

prg_ini:      prg                                               {
                                                                  $$ = astCreate(AST_PROGRAM_INI,0,$1,0,0,0);
                                                                  root = $$;  

                                                                  printf("\nCreating the AST...");
                                                                  //astPrintTree(root,0);
                                                                  printf("\nOk. AST was built!\n");

                                                                  printf("\n\nGenerating the copy of code...");
                                                                  decompile(root);
                                                                  printf("\nOk. Code generated!\n");

                                                                  printf("\n\nSearching for semantic erros...");
                                                                  //semanticSetDeclaration(root);
                                                                  //semanticCheckDeclaration(root);
                                                                  //semanticUtilization(root);
                                                                  printf("\nOk. No semantic errors found!\n");

                                                                  printf("\n\nGenerating the TAC: three address code...\n\n");
                                                                  tac = tacCodeGen(root);
                                                                  tacPrintList(tacReverse(tac));
                                                                  printf("\nOk. TAC generated!\n");
                                
                                                                }
              ;

prg:          prg decl	                                        { $$ = astCreate(AST_PROGRAM,0,$1,$2,0,0); }
              |                                       			{ $$ = 0; }
	          ;
  	
dcl_vr:       dcl_vr decl_type ';'                              { $$ = astCreate(AST_DEC,0,$1,$2,0,0); }
	          |							                        { $$ = 0; }
              ;	

decl_type:    dcl_std 	                                        { $$ = $1; }	
	          | dcl_ptr 		                                { $$ = $1; }
	          | dcl_arr 		                                { $$ = $1; } 
              ;		

decl:         dcl_vr dcl_fn decl_cnt  	                        { $$ = astCreate(AST_DECL,0,$1,$2,0,0); } 
              ;	                                           
                                      
decl_cnt:     ';'                                               { $$ = 0; } 
              |                                                 { $$ = 0; } 
              ;
                      
dcl_std:      dt_tp IDENTIFIER ':' vl	                        { 
                                                                  $$ = astCreate(AST_NDEC,$2,$1,$4,0,0); 
                                                                  $2->dataType = setDataType($1->type);
                                                                }
	          ;                                             
                                                            
dcl_ptr:      dt_tp '$' IDENTIFIER ':' vl	                    { 
                                                                  $$ = astCreate(AST_POINTER_DEC,$3,$1,$5,0,0); 
                                                                  $3->dataType = setDataType($1->type);
                                                                }
	          ;

dcl_arr:      dt_tp IDENTIFIER '['expr']' atrr_dcl_arr          { 
                                                                  $$ = astCreate(AST_ARRAY_DEC,$2,$1,$4,$6,0);  
                                                                  $2->dataType = setDataType($1->type);
                                                                }
	          ;

 
atrr_dcl_arr: ':' vr_lt	                                        { $$ = $2; }
	          |				                                    { $$ = 0; }
	          ;

vr_lt:        vl				                                { $$ = astCreate(AST_ATRR_LIT,0,$1,0,0,0); }
	          | vr_lt vl		                                { $$ = astCreate(AST_ATRR_LIT,0,$1,$2,0,0); }
	          ;


dcl_fn:    	  dt_tp IDENTIFIER '(' dcl_t_fn ')' cmd             { 
                                                                  $$ = astCreate(AST_FUN_DEF,$2,$1,$4,$6,0); 
                                                                  $2->dataType = setDataType($1->type);
                                                                }
	          |  						                        { $$ = 0; }
	          ;

dcl_t_fn:     prm_lst                                           { $$ = $1; }
	          |				                                    { $$ = 0; }
	          ;

prm_lst:      dt_tp IDENTIFIER prm_lst_cnt	                    { 
                                                                  $$ = astCreate(AST_PARAM,$2,$1,$3,0,0); 
                                                                  $2->dataType = setDataType($1->type);
                                                                }
	          | dt_tp '$' IDENTIFIER prm_lst_cnt	            { 
                                                                  $$ = astCreate(AST_PARAM_REF,$3,$1,$4,0,0); 
                                                                  $3->dataType = setDataType($1->type);
                                                                }
	          ;

prm_lst_cnt:  ',' prm_lst 			                            { $$ = $2; }
	          |		                                            { $$ = 0; }
	          ;


blck:         '{' cmd_lst '}'   		                        { $$ = astCreate(AST_BLOCK,0,$2,0,0,0); }
	          ;				

cmd_lst:      cmd cmd_cnt   			                        { $$ = astCreate(AST_LIST,0,$1,$2,0,0); }
	          |				                                    { $$ = 0; }
	          ;

cmd:          in     				                            { $$ = $1; }
	          | atrr				                            { $$ = $1; }
	          | ot	    			                            { $$ = $1; }
	          | if				                                { $$ = $1; }
	          | rtn			                                    { $$ = $1; }
	          | blck				                            { $$ = $1; }
	          ;

cmd_cnt:      ';' cmd_lst			                            { $$ = astCreate(AST_LIST,0,$2,0,0,0); }
	          ;

in:           KW_INPUT IDENTIFIER arr	                        { $$ = astCreate(AST_IN,$2,0,$3,0,0); }
	          |				                                    { $$ = 0; }
	          ;


atrr:         expr  '=' expr 								    { $$ = astCreate(AST_ATRR,0,$1,$3,0,0); }
	          ;

ot:           KW_OUTPUT ot_arg                                  { $$ = astCreate(AST_OUT,0,$2,0,0,0); }
	          ;

ot_arg:       LIT_STRING ot_arg_cnt                             { $$ = astCreate(AST_OUT_ARG_STR,$1,0,$2,0,0); }
	          | expr ot_arg_cnt  	                            { $$ = astCreate(AST_OUT_ARG,0,$1,$2,0,0); }
	          ;

ot_arg_cnt:   ',' ot_arg             	                        { $$ = astCreate(AST_OUT_ARG,0,$2,0,0,0); }
	          |				                                    { $$ = 0; }
	          ;

if:           KW_IF '(' expr ')' if_cmd cmd                     { $$ = astCreate(AST_IF,0,$3,$5,$6,0); }
	          ;

if_cmd:       KW_THEN 				                            { $$ = astCreate(AST_THEN,0,0,0,0,0); }
	          | KW_ELSE			                                { $$ = astCreate(AST_ELSE,0,0,0,0,0); }
	          | KW_LOOP			                                { $$ = astCreate(AST_LOOP,0,0,0,0,0); }
	          ;
	
rtn:          KW_RETURN expr			                        { $$ = astCreate(AST_RETURN,0,$2,0,0,0); }
	          ;


arr:          '['expr']'			                            { $$ = astCreate(AST_INDEX,0,$2,0,0,0); }
	          |				                                    { $$ = 0; }
	          ;

expr:         IDENTIFIER arr		                            { $$ = astCreate(AST_SYMBOL,$1,$2,0,0,0); }
	          | '&' IDENTIFIER		                            { $$ = astCreate(AST_POINTER_ADDR,$2,0,0,0,0); }
	          | '$' IDENTIFIER		                            { $$ = astCreate(AST_POINTER,$2,0,0,0,0); }
	          | LIT_INTEGER			                            { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	          | LIT_TRUE			                            { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	          | LIT_FALSE			                            { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	          | LIT_CHAR			                            { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	          | LIT_STRING			                            { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	          | IDENTIFIER '(' lst_vl ')'                       { $$ = astCreate(AST_FUNC_CALL,$1,$3,0,0,0); }
	          | inv '(' expr ')'		                        { $$ = astCreate(AST_INV_EXPR,0,$1,$3,0,0); }
	          | '(' expr ')'   		                            { $$ = astCreate(AST_PAR_EXPR,0,0,$2,0,0); }
	          | expr '+' expr			                        { $$ = astCreate(AST_ADD,0,$1,$3,0,0); }			
 	          | expr '-' expr			                        { $$ = astCreate(AST_SUB,0,$1,$3,0,0); }		
	          | expr '*' expr			                        { $$ = astCreate(AST_MUL,0,$1,$3,0,0); }
	          | expr '/' expr			                        { $$ = astCreate(AST_DIV,0,$1,$3,0,0); }			
	          | expr '>' expr			                        { $$ = astCreate(AST_GREATER,0,$1,$3,0,0); }	
	          | expr '<' expr			                        { $$ = astCreate(AST_LESS,0,$1,$3,0,0); }	
	          | expr OPERATOR_LE expr		                    { $$ = astCreate(AST_LE,0,$1,$3,0,0); }
	          | expr OPERATOR_GE expr		                    { $$ = astCreate(AST_GE,0,$1,$3,0,0); }
	          | expr OPERATOR_EQ expr	                        { $$ = astCreate(AST_EQ,0,$1,$3,0,0); }
	          | expr OPERATOR_NE expr	                        { $$ = astCreate(AST_NE,0,$1,$3,0,0); }
	          | expr OPERATOR_AND expr	                        { $$ = astCreate(AST_AND,0,$1,$3,0,0); }
	          | expr OPERATOR_OR expr	                        { $$ = astCreate(AST_OR,0,$1,$3,0,0); }
	          ;

inv:          '!'				                                { $$ = astCreate(AST_BOOLEAN_INV,0,0,0,0,0); }
	          |'-'				                                { $$ = astCreate(AST_ARIT_INV,0,0,0,0,0); }
	          ;

lst_vl :      prm				                                { $$ = $1; }
	          |				                                    { $$ = 0; }
	          ;

prm:          expr prms			                                { $$ = astCreate(AST_PASS_PARAM,0,$1,$2,0,0); }
	          ;

prms:         ',' prm			                                { $$ = astCreate(AST_PASS_PARAM,0,$2,0,0,0); }
	          |				                                    { $$ = 0; }
	          ;

vl:           LIT_INTEGER		                                { 
                                                                  $$ = astCreate(AST_LIT_INTEGER,$1,0,0,0,0); 
                                                                  $1->dataType = DATATYPE_BYTE;
                                                                }            
              | LIT_TRUE		                                { 
                                                                  $$ = astCreate(AST_LIT_TRUE,$1,0,0,0,0);
                                                                  $1->dataType = DATATYPE_BOOL;
                                                                }
	          | LIT_FALSE		                                { 
                                                                  $$ = astCreate(AST_LIT_FALSE,$1,0,0,0,0); 
                                                                  $1->dataType = DATATYPE_BOOL;}
              | LIT_CHAR		                                { 
                                                                  $$ = astCreate(AST_LIT_CHAR,$1,0,0,0,0); 
                                                                  $1->dataType = DATATYPE_WORD;}	
              | LIT_STRING	                                    { 
                                                                  $$ = astCreate(AST_LIT_STRING,$1,0,0,0,0); 
                                                                  $1->dataType = DATATYPE_WORD;
                                                                }	
	          ;

dt_tp:        KW_WORD				                            { $$ = astCreate(AST_WORD,0,0,0,0,0); }	
	          | KW_BYTE			                                { $$ = astCreate(AST_BYTE,0,0,0,0,0); }
	          | KW_BOOL			                                { $$ = astCreate(AST_BOOL,0,0,0,0,0); }	         
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

