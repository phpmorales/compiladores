/**
  gv.c

  As funções deste arquivo, se corretamente utilizadas, permitem a
  geração de um grafo no formato dot (graphviz). Ele imprime na saída
  de erro do programa o grafo. Para utilizar, chame gv_init no início
  do programa, depois chame gv_declare para declarar um nó da AST
  (passando o seu tipo - de acordo com ast.h, o pointeiro para o nó da
  AST e o seu nome). Para conectar dois nós da AST, utilize gv_connect
  e para fechar o arquivo utilize gv_close.

  Atenção: não altere este arquivo

  Supondo que o arquivo de saída deste módulo encontra-se no arquivo
  "saida.dot", ele pode ser visualizado da seguinte maneira:

  1 - instale o pacote graphviz
  2 - execute o comando "dot saida.dot -Tpng -o saida.png"
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/ast.h"
#include "../include/gv.h"

static FILE *fp = NULL;

static inline void __gv_test_valid_fp(const char *function_name) {
    if (!fp) {
        fprintf(stderr, "%s foi chamada, mas gv_init não foi chamada antes, abort()\n", function_name);
        abort();
    }
}

static inline void __gv_test_valid_ast_pointer(const char *function_name, const char *pointer) {
    if (!pointer) {
        fprintf(stderr, "%s foi chamada com pointer = NULL\n", function_name);
        abort();
    }
}

static inline char *__gv_description_from_type(int tipo) {

    switch (tipo) {
        case AST_PROGRAM: return "programa";
        case AST_IF_ELSE: return "ifelse";
        case AST_IF: return "if";
        case AST_ELSE: return "else";
        case AST_LOOP: return "loop";
        case AST_INPUT: return "input";
        case AST_OUTPUT: return "output";
        case AST_EQUAL: return "=";
        case AST_RETURN: return "return";
        case AST_CMD_BLCK: return "block";
        case AST_ADD: return "+";
        case AST_SUB: return "-";
        case AST_MUL: return "*";
        case AST_DIV: return "/";
        case AST_OP_AND: return "&&";
        case AST_OP_OR: return "||";
        case AST_OP_NE: return "!=";
        case AST_OP_EQ: return "==";
        case AST_OP_LE: return "<=";
        case AST_OP_GE: return ">=";
        case AST_LESS: return "<";
        case AST_GREAT: return ">";
        case AST_VECTOR: return "[]";

        default:
            fprintf(stderr, "%s: tipo provided is invalid here\n", __FUNCTION__);
            abort();
    }
    fprintf(stderr, "%s: should not get here: \n", __FUNCTION__);
    abort();
}

/**
 * gv_init 
 *
 * Esta função deve ser chamada para inicializar o arquivo onde o
 * grafo será registrado. Um nome de arquivo, opcional, pode ser
 * passado como argumento para esta função. Caso o parâmetro com o
 * nome do arquivo seja NULL, a saída será impressa na saída de erro.
 */
void gv_init(const char *filename) {
    //verificar se gv_init já foi chamada
    if (fp) {
        fprintf(stderr, "%s:%d já foi chamada, abort()\n", __FUNCTION__, __LINE__);
        abort();

    }

    //se o nome do arquivo for válido, abre arquivo com esse nome para escrita
    if (filename) {
        fp = fopen(filename, "w");
        if (!fp) {
            fprintf(stderr, "%s:%d não conseguiu abrir o arquivo %s para escrita\n", __FUNCTION__, __LINE__, filename);
            abort();
        }
    } else {
        fp = stderr;
    }
    fprintf(fp, "digraph G {\n");
    fflush(fp);
}

/**
 * gv_close
 *
 * Esta função deve ser chamada para fechar o arquivo com o grafo
 * registrado. Ela deve ser chamada no final do compilador.
 */
void gv_close(void) {
    __gv_test_valid_fp(__FUNCTION__);
    fprintf(fp, "}\n");
    fclose(fp);
}

/**
 * gv_declare
 *
 * Esta função deve ser chamada para declarar um nó da AST,
 * registrando esse novo nó no arquivo. Ela tem três parâmetros: 

 * 1/ tipo, que deve ser obrigatoriamente um dos valores das
 * constantes declaradas no arquivo ast.h; 

 * 2/ pointer, que deve ser um pointeiro para o nó da árvore AST que
 * está sendo declarado servindo a partir de agora como identificador
 * único do nó; e 

 * 3/ name, que deve ser um lexema válido somente se o tipo for um
 * desses três valores: AST_IDENTIFICADOR (o lexema do
 * identificador), AST_LITERAL (o lexema do literal) ou
 * AST_FUNCAO (o lexema do identificador da função).
 */
void gv_declare(const int tipo, const void *pointer, char *name) {
    __gv_test_valid_fp(__FUNCTION__);
    __gv_test_valid_ast_pointer(__FUNCTION__, pointer);

    char *description = NULL;

    switch (tipo) {
        case AST_DEC_FUNC:
        case AST_FUNC_CALL:
        case AST_VAR:
        case AST_LIT_INTEGER:
        case AST_LIT_TRUE:
        case AST_LIT_FALSE:
        case AST_LIT_CHAR:
        case AST_LIT_STRING:
            if (!name) {
                fprintf(stderr, "%s: name should be not NULL: %d \n", __FUNCTION__ , tipo);
                //abort();
            }
            description = name;
            break;
        case AST_LIST_VAR:
        case AST_PROGRAM:
        case AST_IF_ELSE:
        case AST_IF:
        case AST_ELSE:
        case AST_LOOP:
        case AST_INPUT:
        case AST_OUTPUT:
        case AST_EQUAL:
        case AST_RETURN:
        case AST_CMD_BLCK:
        case AST_ADD:
        case AST_SUB:
        case AST_MUL:
        case AST_DIV:
        case AST_OP_AND:
        case AST_OP_OR:
        case AST_OP_NE:
        case AST_OP_EQ:
        case AST_OP_LE:
        case AST_OP_GE:
        case AST_LESS:
        case AST_GREAT:
        case AST_VECTOR:
            if (name){
                fprintf (stderr, "%s: name should be NULL: %d \n", __FUNCTION__ , tipo);
                abort();
            }
            description = __gv_description_from_type (tipo);
            break;
        default:
            fprintf(stderr, "%s: unknow tipo provided: %d \n", __FUNCTION__ , tipo);
            //abort();
    }

    fprintf(fp, "node_%p [label=\"%s\"]\n", pointer, description);
    fflush(fp);
}

/**
 * gv_connect
 *
 * Esta função deve ser utilizada para conectar dois nós da AST na
 * saída em dot. Ela recebe como parâmetro ponteiros para os dois nós
 * da AST que devem ser conectados. Note que esses ponteiros servem
 * como identificadores únicos dos nós da AST.
 */
void gv_connect(const void *p1, const void *p2) {
    __gv_test_valid_fp(__FUNCTION__);
    __gv_test_valid_ast_pointer(__FUNCTION__, p1);
    __gv_test_valid_ast_pointer(__FUNCTION__, p2);

    fprintf(fp, "node_%p -> node_%p\n", p1, p2);
    fflush(fp);
}
