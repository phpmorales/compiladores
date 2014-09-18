#include "hash.h"
#ifndef AST_HEADER
#define AST_HEADER

#define AST_PROGRAM             0
#define AST_VECTOR_ID           1
#define AST_VECTOR              2
#define AST_DIV                 3
#define AST_ADD                 4
#define AST_MUL                 5
#define AST_SUB                 6
#define AST_SCALAR_ASS          7
#define AST_SYMBOL              8
#define AST_OP_AND              9
#define AST_OP_OR               10
#define AST_OP_LE               11
#define AST_OP_GE               12 
#define AST_OP_EQ               13
#define AST_OP_NE               14
#define AST_LESS                15
#define AST_GREAT               16 
#define AST_KW_WORD             17
#define AST_KW_BYTE             18
#define AST_KW_BOOL             19
#define AST_LIT_INTEGER         20
#define AST_LIT_TRUE	        21
#define AST_LIT_FALSE           22
#define AST_LIT_CHAR	        23
#define AST_LIT_STRING          24
#define AST_IF                  25
#define AST_IF_ELSE             26
#define AST_ELSE                57
#define AST_LOOP                27
#define AST_DEC_GLOBAL          28
#define AST_DEC_LOCAL           29
#define AST_VAR                 30
#define AST_PONT                31
#define AST_LIST_VAR            32
#define AST_LIST_VEC            33 
#define AST_LIST_FUNC           34
#define AST_LIST_OUTPUT         35
#define AST_OUTPUT              36
#define AST_INPUT               37
#define AST_RETURN              38        
#define AST_CMD                 39
#define AST_CMD_LIST            40
#define AST_CMD_BLCK            41
#define AST_EQUAL               42
#define AST_EQUAL_VEC           43
#define AST_PRM_FUNC            44
#define AST_PRM_FUNC_ID         45
#define AST_PRM_FUNC_IDLIST     46
#define AST_PRM_DEC_FUNC        47
#define AST_PRM_DEC_FUNC_LIST   48
#define AST_PRM_FUNC_VALUE      49
#define AST_PRM_FUNC_VALUE_LIST 50
#define AST_FUNC_CALL           51
#define AST_PONT_END            52
#define AST_PONT_VAL            53
#define AST_DEC_FUNC            54
#define AST_GLOBAL              55
#define AST_SINGLE_OUTPUT       56

#define MAX_CHILDREN 4

typedef struct AST_NODE {
    int lineNumber;
    int type;
    HASH_NODE* symbol;
    struct AST_NODE *son[MAX_CHILDREN];
} ast;

FILE *input;
FILE *output;

ast *astCreate(int type, HASH_NODE* symbol, ast* s0, ast* s1, ast* s2, ast* s3);
void  astPrintSingle(ast *node, int level);
int astPrintTree(ast *node, int intent);
void printTab(int level);

#endif
