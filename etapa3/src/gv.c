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
  "graph.dot", ele pode ser visualizado da seguinte maneira:

  1 - instale o pacote graphviz
  2 - execute o comando "dot graph.dot -Tpng -o saida.png"

**/

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
        case AST_PROGRAM_INI:   return "START";
        case AST_PROGRAM:       return "PROGRAM";
        case AST_IF:            return "IF";
		case AST_CMD_THEN:      return "THEN";
        case AST_CMD_ELSE:      return "ELSE";
		case AST_CMD_LOOP:      return "LOOP";		
        case AST_IN:            return "INPUT";
        case AST_OUT:           return "OUTPUT";	
		case AST_BLOCK:         return "BLOCK";		
        case AST_RETURN:        return "RETURN";		
        case AST_ATRR:          return "=";        
        case AST_ADD:           return "+";
        case AST_SUB:           return "-";
        case AST_MUL:           return "*";
        case AST_DIV:           return "/";
        case AST_AND:           return "&&";
        case AST_OR:            return "||";
        case AST_NE:            return "!=";
        case AST_EQ:            return "==";
        case AST_LE:            return "<=";
        case AST_GE:            return ">=";
        case AST_LESS:          return "<";
        case AST_GREATER:       return ">";			
		case AST_BOOLEAN_INV:   return "!";
		case AST_ARIT_INV:      return "-";
		case AST_DEC:			return "DEC";
		case AST_DECL:			return "DECL";
		case AST_ATRR_LIT:      return "ATRR LIT";
		case AST_PARAM_REF:     return "PARAM REF";
		case AST_PARAM:         return "PARAM";
		case AST_CMD_LIST:      return "CMD LIST";
		case AST_OUT_ARG:       return "OUT ARG";
		case AST_INDEX:         return "INDEX";
		case AST_POINTER_ADDR:  return "POINTER ADDR";
		case AST_POINTER:    	return "POINTER";
		case AST_FUNC_CALL:     return "FUNC CALL";
		case AST_INV_EXPR:      return "EXPR";
		case AST_PAR_EXPR:      return "PAR EXPR";
		case AST_PASS_PARAM:    return "PASS PARAM";
        case AST_WORD:          return "WORD";
        case AST_BOOL:          return "BOOL";
        case AST_BYTE:          return "BYTE";
		case AST_UNDEFINIED:    return "UNIDEFINIED";
        default:                return "UNIDEFINIED";
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
		case AST_OUT_ARG_STR:
            description = "AST_OUT_ARG_STR";
            break;
        case AST_FUN_DEF:
        case AST_FUNC_CALL:
        case AST_NDEC:
        case AST_POINTER_DEC:
        case AST_ARRAY_DEC:
        case AST_SYMBOL:
		case AST_PARAM_REF:     
		case AST_PARAM:  
        case AST_IN:
        case AST_WORD:
        case AST_BOOL:
        case AST_BYTE:
        case AST_PROGRAM_INI:
        case AST_PROGRAM:
        case AST_IF:
		case AST_CMD_THEN:
        case AST_CMD_ELSE:
		case AST_CMD_LOOP:
        case AST_OUT:
		case AST_OUT_ARG:
		case AST_BLOCK:
        case AST_RETURN:
        case AST_ATRR:
        case AST_ADD:
        case AST_SUB:
        case AST_MUL:
        case AST_DIV:
        case AST_AND:
        case AST_OR:
        case AST_NE:
        case AST_EQ:
        case AST_LE:
        case AST_GE:
        case AST_LESS:
        case AST_GREATER:
		case AST_BOOLEAN_INV:
		case AST_ARIT_INV:
		case AST_DEC:			
		case AST_DECL:			
		case AST_ATRR_LIT:                   
		case AST_CMD_LIST:                 
		case AST_INDEX:         
		case AST_POINTER_ADDR:  
		case AST_POINTER:    	
		case AST_INV_EXPR:      
		case AST_PAR_EXPR:        
		case AST_PASS_PARAM:    
		case AST_UNDEFINIED:    
            if (name){
                description = name;
            }
            else{
                description = __gv_description_from_type (tipo);            
            }           
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
