#include <stdio.h>
#include <stdlib.h>
#include "../include/ast.h"
#include "../include/hash.h"
#include "../include/gv.h"

extern int getLineNumber(void);
extern FILE * output;
int lastLevel;

ast * astCreate(int type, HASH_NODE * symbol, ast * s0, ast * s1, ast * s2, ast * s3) {
    ast * node = (ast *) malloc(sizeof (ast));
    node->lineNumber = getLineNumber();
    node->type = type;
    node->symbol = symbol;
    node->son[0] = s0;
    node->son[1] = s1;
    node->son[2] = s2;
    node->son[3] = s3;   

    return node;
}

void astPrintSingle(ast * node, int level) {
    if (!node)
        return;

    if(node->son[0]){
        //if(node->son[0]->symbol){
            //gv_declare(node->son[0]->type,node,node->symbol);
        //}
        //else{
            //gv_declare(node->son[0]->type,node,NULL);
        //}           
        //gv_connect(node,node->son[0]);
    }

    if(node->son[1]){
        //if(node->son[1]->symbol){
            //gv_declare(node->son[1]->type,node,node->symbol);
        //}
        //else{
            //gv_declare(node->son[1]->type,node,NULL);
        //}           
       // gv_connect(node,node->son[1]);
    }

    if(node->son[2]){
        //if(node->son[2]->symbol){
            //gv_declare(node->son[2]->type,node,node->symbol);
        //}
        //else{
            //gv_declare(node->son[2]->type,node,NULL);
        //}           
       // gv_connect(node,node->son[2]);
    }

    if(node->son[3]){
        //if(node->son[3]->symbol){
         //   gv_declare(node->son[3]->type,node,node->symbol);
        //}
        //else{
           //gv_declare(node->son[3]->type,node,NULL);
        //}           
        //gv_connect(node,node->son[3]);
    }

    //fprintf(stderr, "\n");
    fprintf(stderr, "\n%d: ", node->lineNumber);
    int i;
    for (i = 0; i < level; i++) {
        fprintf(stderr, "  ");
    }

    switch (node->type) {

        case AST_SCALAR_ASS: fprintf(stderr, "AST_SCALAR_ASS");
            break;
        case AST_SYMBOL:
            fprintf(stderr, "AST_SYMBOL");            
            fprintf(output, "%s", node->symbol->text);
            break;
            // Tipos de dados
        case AST_KW_WORD:
            fprintf(stderr, "AST_KW_WORD");
            fprintf(output, "word");
            break;
        case AST_KW_BYTE:
            fprintf(stderr, "AST_KW_BYTE");
            fprintf(output, "byte");
            break;
        case AST_KW_BOOL:
            fprintf(stderr, "AST_KW_BOOL");
            fprintf(output, "bool");
            break;
            // Operaçoes
        case AST_DIV:
            fprintf(stderr, "AST_DIV");
            astPrintSingle(node->son[0], level + 1);        
            fprintf(output, "/");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_ADD:
            fprintf(stderr, "AST_ADD");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "+");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_MUL:
            fprintf(stderr, "AST_MUL");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "*");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_SUB:
            fprintf(stderr, "AST_SUB");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "-");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_OP_AND:
            fprintf(stderr, "AST_OP_AND");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "&&");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_OP_OR:
            fprintf(stderr, "AST_OP_OR");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "||");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_OP_LE:
            fprintf(stderr, "AST_OP_LE");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "<=");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_OP_GE:
            fprintf(stderr, "AST_OP_GE");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ">=");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_OP_EQ:
            fprintf(stderr, "AST_OP_EQ");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "==");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_OP_NE:
            fprintf(stderr, "AST_OP_NE");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "!=");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_LESS:
            fprintf(stderr, "AST_LESS");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "<");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_GREAT:
            fprintf(stderr, "AST_GREAT");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ">");
            astPrintSingle(node->son[1], level + 1);
            break;
            // Literais
        case AST_LIT_INTEGER:
            fprintf(stderr, "AST_LIT_INTEGER");
            fprintf(output, "%s", node->symbol->text);
            break;
        case AST_LIT_TRUE:
            fprintf(stderr, "AST_LIT_TRUE");
            fprintf(output, "%s", node->symbol->text);
            break;
        case AST_LIT_FALSE:
            fprintf(stderr, "AST_LIT_FALSE");
            fprintf(output, "%s", node->symbol->text);
            break;
        case AST_LIT_CHAR:
            fprintf(stderr, "AST_LIT_CHAR");
            fprintf(output, "%s", node->symbol->text);
            break;
        case AST_LIT_STRING:
            fprintf(stderr, "AST_LIT_STRING");
            fprintf(output, "%s", node->symbol->text);
            break;
            // Fluxo
        case AST_IF:
            fprintf(stderr, "AST_IF");
            fprintf(output, "if (");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ") then");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_IF_ELSE:
            fprintf(stderr, "AST_IF_ELSE");
            fprintf(output, "if (");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ") then");
            astPrintSingle(node->son[1], level + 1);
            fprintf(output, "\nelse");
            astPrintSingle(node->son[2], level + 1);
            break;
        case AST_ELSE:
            fprintf(stderr, "AST_ELSE");
            fprintf(output, "if (");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ") else ");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_LOOP:
            fprintf(stderr, "AST_LOOP");
            fprintf(output, "if (");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ")\nloop");
            astPrintSingle(node->son[1], level + 1);
            fprintf(output, ";\n");
            break;
        case AST_DEC_GLOBAL: fprintf(stderr, "AST_DEC_GLOBAL");
            break;
        case AST_DEC_LOCAL: fprintf(stderr, "AST_DEC_LOCAL");
            break;
            // Declaracoes
        case AST_VAR:
            fprintf(stderr, "AST_VAR");
            //fprintf(output, "\n"); 	
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, ":");
            astPrintSingle(node->son[1], level + 1);
            fprintf(output, ";\n");
            break;
        case AST_VECTOR:
            fprintf(stderr, "AST_VECTOR");
            //fprintf(output, "\n"); 	
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, "[");
            astPrintSingle(node->son[1], level + 1);
            fprintf(output, "]");
            if (node->son[2]) {
                fprintf(output, ":");
                astPrintSingle(node->son[2], level + 1);
            }
            fprintf(output, ";\n");
            break;
        case AST_PONT:
            fprintf(stderr, "AST_PONT");
            //fprintf(output, "\n"); 	
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, " $");
            fprintf(output, "%s", node->symbol->text);
            if (node->son[1]) {
                fprintf(output, ":");
                astPrintSingle(node->son[1], level + 1);
            }
            fprintf(output, ";\n");
            break;
        case AST_LIST_VAR:
            fprintf(stderr, "AST_LIST_VAR");
            astPrintSingle(node->son[0], level);
            astPrintSingle(node->son[1], level);
            break;
        case AST_LIST_VEC: fprintf(stderr, "AST_LIST_VEC");
            break;
        case AST_LIST_FUNC: fprintf(stderr, "AST_LIST_FUNC");
            break;
        case AST_CMD:
            fprintf(stderr, "AST_CMD");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_CMD_LIST:
            fprintf(stderr, "AST_CMD_LIST");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ";\n");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_CMD_BLCK:
            fprintf(stderr, "AST_CMD_BLCK");
            fprintf(output, "\n{\n");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "}\n");
            break;
            // Comands
        case AST_EQUAL:
            fprintf(stderr, "AST_EQUAL");
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, "=");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_EQUAL_VEC:
            fprintf(stderr, "AST_EQUAL_VEC");
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, "[");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "]");
            fprintf(output, "=");
            astPrintSingle(node->son[1], level + 1);
            break;
            // ARRUMEI
        case AST_OUTPUT:
            fprintf(stderr, "AST_OUTPUT");
            fprintf(output, "output ");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_SINGLE_OUTPUT:
            fprintf(stderr, "AST_SINGLE_OUTPUT");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_LIST_OUTPUT:
            fprintf(stderr, "AST_LIST_OUTPUT");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ", ");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_INPUT:
            fprintf(stderr, "AST_INPUT");
            fprintf(output, "input");
            fprintf(output, " %s", node->symbol->text);
            break;
        case AST_RETURN:
            fprintf(stderr, "AST_RETURN");
            fprintf(output, "return ");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_VECTOR_ID:
            fprintf(stderr, "AST_VECTOR_ID");
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, "[");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, "]");
            break;
        case AST_FUNC_CALL:
            fprintf(stderr, "AST_FUNC_CALL");
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, "(");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ") ");
            break;
        case AST_PONT_END:
            fprintf(stderr, "AST_PONT_END");
            fprintf(output, " &");
            fprintf(output, "%s", node->symbol->text);
            break;
        case AST_PONT_VAL:
            fprintf(stderr, "AST_PONT_VAL");
            fprintf(output, " *");
            fprintf(output, "%s", node->symbol->text);
            break;
            // Parametros
        case AST_PRM_FUNC:
            fprintf(stderr, "AST_PRM_FUNC");
            break;
        case AST_PRM_FUNC_ID:
            fprintf(stderr, "AST_PRM_FUNC_ID");
            fprintf(output, " %s", node->symbol->text);
            break;
        case AST_PRM_FUNC_IDLIST:
            fprintf(stderr, "AST_PRM_FUNC_IDLIST");
            fprintf(output, " %s", node->symbol->text);
            if (node->son[0])
                fprintf(output, ",");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_PRM_DEC_FUNC:
            fprintf(stderr, "AST_PRM_DEC_FUNC");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, " %s", node->symbol->text);
            break;
        case AST_PRM_DEC_FUNC_LIST:
            fprintf(stderr, "AST_PRM_DEC_FUNC_LIST");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, ",");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_PRM_FUNC_VALUE:
            fprintf(stderr, "AST_PRM_FUNC_VALUE");
            astPrintSingle(node->son[0], level + 1);
            break;
        case AST_PRM_FUNC_VALUE_LIST:
            fprintf(stderr, "AST_PRM_FUNC_VALUE_LIST");
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, ",");
            astPrintSingle(node->son[1], level + 1);
            break;
        case AST_DEC_FUNC:
            fprintf(stderr, "AST_DEC_FUNC");
            ;
            //fprintf(output, "\n"); 	
            astPrintSingle(node->son[0], level + 1);
            fprintf(output, " %s", node->symbol->text);
            fprintf(output, "(");
            astPrintSingle(node->son[1], level + 1);
            fprintf(output, ") ");
            astPrintSingle(node->son[2], level + 1);
            astPrintSingle(node->son[3], level + 1);           
            fprintf(output, ";\n");
            break;
        case AST_GLOBAL: fprintf(stderr, "AST_GLOBAL");
            break;
        default: fprintf(stderr, "ast UNKNOWN");
            break;
    }

    if (node->symbol)
        if (node->symbol->text)
            fprintf(stderr, " - %s", node->symbol->text);
}


// print a esquerda

int astPrintTree(ast * node, int level) {
    if(node){
        astPrintSingle(node, 0);
        printf("\n\n");
        return 1;
    }
    else{
        return 0;
    }
}

void printTab(int level){
    int i;
    for(i = 0; i<level; i++)
        fprintf(output, " - ");
}




