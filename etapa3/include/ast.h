#include    "hash.h"

#ifndef     AST_HEADER
#define     AST_HEADER

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
#define		AST_CMD_LIST        	112
#define		AST_IN              	114
#define		AST_ATRR            	115
#define		AST_OUT             	116
#define		AST_OUT_ARG         	117
#define		AST_IF              	118
#define		AST_CMD_THEN        	119
#define		AST_CMD_ELSE        	120
#define		AST_CMD_LOOP        	121
#define		AST_RETURN          	122
#define		AST_INDEX           	123
#define		AST_SYMBOL          	124
#define		AST_POINTER_ADDR        125
#define		AST_POINTER    	        126
#define		AST_FUNC_CALL       	128
#define		AST_INV_EXPR        	129
#define		AST_PAR_EXPR        	130
#define		AST_LE              	131
#define		AST_GE              	132
#define		AST_EQ              	133
#define		AST_NE              	134
#define		AST_AND             	135
#define		AST_OR              	136
#define		AST_ADD             	137
#define		AST_SUB             	138
#define		AST_MUL             	139
#define		AST_DIV             	140
#define		AST_GREATER         	141
#define		AST_LESS            	142
#define		AST_BOOLEAN_INV     	143
#define		AST_ARIT_INV        	144
#define		AST_PASS_PARAM      	145
#define		AST_WORD            	146
#define		AST_BOOL            	147
#define		AST_BYTE            	148

#define MAX_SONS 4

typedef struct AST_NODE {
    int lineNumber;
    int type;
    HASH_NODE* symbol;
    struct AST_NODE *son[MAX_SONS];
} ast;

FILE    *input;
FILE    *output;

ast*    astCreate(int type, HASH_NODE *symbol, ast *s0,ast *s1, ast *s2, ast *s3);
void    astPrintNode (ast *node);
void    astPrintTree (ast* node, int level);
void    decompile(ast *root);

#endif
