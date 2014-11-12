/*
 *
 * Author: Miller Biazus
 *		   Pedro Henrique Pinto Morales
 * UFRGS - Instituto de Informática
 * Etapa 4 - Compiladores - Prof. Marcelo de Oliveira Johann
 * 2014/2
 *
 */

/*
 *
 * ast.h
 * 
 * Funções públicas do módulo ast. Verifique a implementação para
 * maiores detalhes de como utilizar cada uma. 
 * 
 */

#ifndef     __AST_H__
#define     __AST_H__

#include    "hash.h"

#define		AST_PROGRAM_INI			100
#define		AST_PROGRAM				101
#define		AST_DEC					102
#define		AST_DECL				103
#define		AST_NDEC				104
#define		AST_POINTER_DEC     	105
#define		AST_ARRAY_DEC       	106
#define		AST_ATRR_LIT        	107
#define		AST_FUN_DEF         	108
#define		AST_PARAM_REF       	109
#define		AST_PARAM           	110
#define		AST_BLOCK           	111
#define		AST_LIST        	    112
#define		AST_IN              	113
#define		AST_ATRR            	114
#define		AST_OUT             	115
#define		AST_OUT_ARG         	116
#define     AST_OUT_ARG_STR         117
#define		AST_IF              	118
#define		AST_THEN        	    119
#define		AST_ELSE        	    120
#define		AST_LOOP        	    121
#define		AST_RETURN          	122
#define		AST_INDEX           	123
#define		AST_SYMBOL          	124
#define     AST_LIT_INTEGER         125
#define     AST_LIT_TRUE            126
#define     AST_LIT_FALSE           127
#define     AST_LIT_CHAR            128
#define     AST_LIT_STRING          129
#define		AST_POINTER_ADDR        130
#define		AST_POINTER    	        131
#define		AST_FUNC_CALL       	132
#define		AST_INV_EXPR        	133
#define		AST_PAR_EXPR        	134
#define		AST_LE              	135
#define		AST_GE              	136
#define		AST_EQ              	137
#define		AST_NE              	138
#define		AST_AND             	139
#define		AST_OR              	140
#define		AST_ADD             	141
#define		AST_SUB             	142
#define		AST_MUL             	143
#define		AST_DIV             	144
#define		AST_GREATER         	145
#define		AST_LESS            	146
#define		AST_BOOLEAN_INV     	147
#define		AST_ARIT_INV        	148
#define		AST_PASS_PARAM      	149
#define		AST_WORD            	150
#define		AST_BOOL            	151
#define		AST_BYTE            	152
#define		AST_UNDEFINED         	153

#define     AST_SONS 4

typedef struct ast_node {
    int type;
    int lineNumber;
	int printFlag;
    hash_t* symbol;
    struct ast_node *son[AST_SONS];
} ast_t;


FILE *input;
FILE *outputAST;

/***************************************
 * Function: astCreate
 * Description:
 * Input:
 * Output:
 ***************************************/
ast_t* astCreate(int type, hash_t *symbol, ast_t *s0,ast_t *s1, ast_t *s2, ast_t *s3);

/***************************************
 * Function: astPrintNode
 * Description:
 * Input:
 * Output:
 ***************************************/
void astPrintNode(ast_t *node);

/***************************************
 * Function: astPrintTree
 * Description:
 * Input:
 * Output:
 ***************************************/
void astPrintTree(ast_t* node, int level);

/***************************************
 * Function: decompile
 * Description:
 * Input:
 * Output:
 ***************************************/
void decompile(ast_t *root);

#endif

