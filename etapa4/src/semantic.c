/*
 *
 * Author: Miller Biazus
 *		   Pedro Henrique Pinto Morales
 * UFRGS - Instituto de Informática
 * Etapa 4 - Compiladores - Prof. Marcelo de Oliveira Johann
 * 2014/2
 *
 */

#include "../include/gv.h"
#include "../include/semantic.h"
#include "../include/ast.h"
#include "../include/hash.h"
#include "../include/y.tab.h"

ast_t *funcAst;

int guardaTypeRet = 0;
int scalDecl = 0; 
int pointer = 0; 
int ilegalExp = 0;

/***************************************
 * Function: setDataType
 * Description:
 * Input:
 * Output:
 ***************************************/
int setDataType ( int astType ) {
	switch ( astType ) {
		case AST_WORD: return DATATYPE_WORD;
		case AST_BOOL: return DATATYPE_BOOL;
		case AST_BYTE: return DATATYPE_BYTE;
	}

    return 0;
}

void semanticDeclaration ( ast_t *node ) {

	if( node == 0 ) return;

	int i;

	if(
        node->type == AST_NDEC || 
		node->type == AST_POINTER_DEC || 
        node->type == AST_ARRAY_DEC ||
		node->type == AST_FUN_DEF || 
        node->type == AST_PARAM ||
        node->type == AST_PARAM_REF
    ){
		if( node->symbol == 0 ) {
			fprintf( stderr, "Erro na linha %d: Declarao nao tem o nome do identificador.\n", node->lineNumber );
		} 
        else {
            
			if ( node->symbol->type != IDENTIFIER )
				fprintf( stderr, "Erro na linha %d: Simbolo %s já foi definido anteriormente.\n", node->lineNumber, node->symbol->text );
			
            switch ( node->type ) {
                case AST_NDEC:          node->symbol->type = SYMBOL_SCALAR;    break;
                case AST_POINTER_DEC:   node->symbol->type = SYMBOL_POINTER;   break;
                case AST_ARRAY_DEC:     node->symbol->type = SYMBOL_VECTOR;    break;
                case AST_FUN_DEF:       node->symbol->type = SYMBOL_FUNCTION;  break;
                case AST_PARAM:         node->symbol->type = SYMBOL_SCALAR;    break;
                case AST_PARAM_REF:     node->symbol->type = SYMBOL_POINTER;   break;
                default: break;
		    }
	    }
    }
	
    for ( i = 0; i < AST_SONS; ++i ) {
		semanticDeclaration ( node->son[i] );
	}

}

void semanticUtilization ( ast_t *node ) {
	if( node == 0 ) return;

	int i;

	// Make sure only declared scalars are being used as scalars
	// Make sure only declared scalars are being used as scalars
	if( node->type == AST_ATRR ){
		if (node->son[0]->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr, "Erro na linha %d: Vetor declarado %s sendo usado como escalar.\n", node->lineNumber, node->symbol->text);
		}
         else if(node->son[0]->symbol->type == SYMBOL_FUNCTION) {
			fprintf(stderr, "Erro na linha %d: Funcao declarada %s sendo usada como escalar.\n", node->lineNumber, node->symbol->text);
		} 
        else if (node->son[0]->symbol->type != SYMBOL_SCALAR && node->symbol->type != SYMBOL_POINTER){
			fprintf(stderr, "Erro na linha %d: Variavel %s nao declarada.\n", node->lineNumber, node->symbol->text);
		}
        else{
			fprintf(stderr, "Erro na linha %d: desconecido.\n", node->lineNumber);
        }
	}
   /*
	// Make sure only declared vectors are being used as vectors
	else if(node->type == AST_ARRAY_DEC){
		if (node->symbol->type == VAR || node->symbol->type == PARAM) {
			fprintf(stderr, "Erro na linha %d: Variavel declarada %s sendo usada como vetor.\n", node->lineNumber, node->symbol->text);
		} else if (node->symbol->type == FUNCTION) {
			fprintf(stderr, "Erro na linha %d: Funcao declarada %s sendo usada como vetor.\n", node->lineNumber, node->symbol->text);
		} else if (node->symbol->type != VECTOR ){
			fprintf(stderr, "Erro na linha %d: Vetor %s nao declarado.\n", node->lineNumber, node->symbol->text);
		}
	}

	// Make sure only declared functions are being used as functions
	else if(node->type == AST_FUN_DEF){
		if (node->symbol->type == VAR || node->symbol->type == PARAM) {
			fprintf(stderr, "Erro na linha %d: Variavel declarada %s sendo usada como funcao.\n", node->lineNumber, node->symbol->text);
		} else if (node->symbol->type == VECTOR) {
			fprintf(stderr, "Erro na linha %d: Vetor declarada %s sendo usada como funcao.\n", node->lineNumber, node->symbol->text);
		} else if (node->symbol->type != FUNCTION){
			fprintf(stderr, "Erro na linha %d: Funcao %s nao declarada.\n", node->lineNumber, node->symbol->text);
		} else if (node->symbol->type == FUNCTION) {
			checkFunctionCallParameters(node);
		}
	}*/

    for ( i = 0; i < AST_SONS; ++i ) {
		semanticUtilization ( node->son[i] );
	}

}

/*
// Verifica os parametros de chamada de funcao
void checkFunctionCallParameters(ASTREE *node) {
	if(node == 0) return;
	if(node->type == ASTREE_FUNC_CALL){
		ASTREE *params = node->symbol->ast;
		if(node->son[0]){
		if(params->type == ASTREE_PARAM_DECFUNC && (node->son[0]->type != ASTREE_PARAM_FUNC_ID) && (node->son[0]->type != ASTREE_PARAM_FUNC_VALUE))
			fprintf(stderr,"Erro na linha %d: chamada de funcao %s com numero invalido de parametros.\n", node->lineNumber, node->symbol->text);
		else if (params->type == ASTREE_PARAM_DECFUNC_LIST && node->son[0]->type != ASTREE_PARAM_FUNC_IDLIST && node->son[0]->type != ASTREE_PARAM_FUNC_VALUELIST)
			fprintf(stderr,"Erro na linha %d: chamada de funcao %s com numero invalido de parametros.\n", node->lineNumber, node->symbol->text);
		else checkListParams(params, node->son[0], node);
		}
	}
}

// Verifica as declaracoes os parametros de declaracoes de funcoes e a validade das chamadas se estao de acordo com a declaracao
void checkListParams(ASTREE *decParams, ASTREE *callParams, ASTREE *node){
	int aux = 0;
	if (callParams->type == ASTREE_PARAM_FUNC_VALUELIST || callParams->type == ASTREE_PARAM_FUNC_VALUE) 
		aux = 1;
	else if (callParams->type == ASTREE_PARAM_FUNC_IDLIST || callParams->type == ASTREE_PARAM_FUNC_ID) 
		aux = 0;

	if (((decParams->son[1] == 0) && (callParams->son[aux] != 0)) ||
		((decParams->son[1] != 0) && (callParams->son[aux] == 0)))
	{
		fprintf(stderr,"Erro na linha %d: chamada de funcao %s com numero invalido de parametros.\n", node->lineNumber, node->symbol->text);
	}
	else
	{
	int parameterType;
		if (callParams->son[aux])
			parameterType = checkExpressionType(callParams->son[aux]);
		if (decParams->son[1] && decParams->son[1]->symbol){
			if(decParams->son[1]->symbol->dataType == DATA_TYPE_BOOL && parameterType != DATA_TYPE_BOOL){
				printf("Erro na linha %d: chamade de funcao %s com tipo de parametro invalido.\n", node->lineNumber, node->symbol->text);
				return;
				}else if (decParams->son[1]->symbol->dataType == DATA_TYPE_WORD
					&& parameterType != DATA_TYPE_BYTE){
					printf("Erro na linha %d: chamade de funcao %s com tipo de parametro invalido.\n", node->lineNumber, node->symbol->text);
					return;
				} else if(decParams->son[1]->symbol->dataType == DATA_TYPE_BYTE && parameterType == DATA_TYPE_WORD){
					printf("Erro na linha %d: chamade de funcao %s com tipo de parametro invalido.\n", node->lineNumber, node->symbol->text);
					return;
				}
		}
	}

	if (((decParams->son[1] != 0) && (callParams->son[aux] != 0)))
		checkListParams(decParams->son[1], callParams->son[aux], node);
}

// Retorna o tipo de cada expressao
int checkExpressionType(ASTREE *expression){
	int dataType1, dataType2;
	if(expression == 0) return -1;
	else {
		if(expression->symbol) return expression->symbol->dataType;
		else {
			if(expression->type == ASTREE_LESS || expression->type == ASTREE_GREAT || expression->type == ASTREE_OP_LE ||
				expression->type == ASTREE_OP_GE || expression->type == ASTREE_OP_EQ || expression->type == ASTREE_OP_NE ||
				expression->type == ASTREE_OP_AND || expression->type == ASTREE_OP_OR) 
				return DATA_TYPE_BOOL;
			if (expression->son[0])
			dataType1 = checkExpressionType(expression->son[0]);
			if (expression->son[1])
			dataType2 = checkExpressionType(expression->son[1]);			
			if(dataType1 == DATA_TYPE_BYTE || dataType2 == DATA_TYPE_BYTE) return DATA_TYPE_BYTE;
			if(dataType1 == DATA_TYPE_WORD || dataType2 == DATA_TYPE_WORD) return DATA_TYPE_WORD;
			else return DATA_TYPE_BOOL;
		} 
	}
}

// Verifica os nodos de adição, onde se houver ponteiro retorna 1 se nao houver retorna 0 (recursivo)
int checkAddPont (ASTREE* node, int lineNumber){
	if(node == 0) return 0;

	if (node->type == ASTREE_ADD){
		if (node->son[0]){
			if (node->son[0]->symbol){
			if (node->son[0]->symbol->type == PONT)
				return 1;
		}
			if (node->son[0]->type == ASTREE_ADD)
				if(checkAddPont(node->son[0], lineNumber))
					return 1;
		}
		if (node->son[1]){
			if (node->son[1]->symbol){
			if (node->son[1]->symbol->type == PONT)
				return 1;
		}
			if (node->son[1]->type == ASTREE_ADD)
				if(checkAddPont(node->son[0], lineNumber))
					return 1;
		}
	}
	return 0;	
}

// Checa tipos de dados para =
void checkEqualType(ASTREE* node, int dataType){
	if (node->type != ASTREE_PONT && node->type != ASTREE_FUNC_CALL){
	if (node->son[0]){
		if (node->son[0]->type == ASTREE_LIT_STRING)
			fprintf(stderr, "Erro na linha %d: tipo invalido (string) na expressao.\n", node->lineNumber);

		if (checkExpressionType(node->son[0]) != dataType){
			if(checkExpressionType(node->son[0]) == DATA_TYPE_BOOL)
				fprintf(stderr, "Erro na linha %d: tipo invalido na expressao.\n", node->lineNumber);
		}
		else
			checkEqualType(node->son[0], dataType);
	}

	if (node->son[1]){
		if (node->son[1]->type == ASTREE_LIT_STRING)
			fprintf(stderr, "Erro na linha %d: tipo invalido (string) na expressao.\n", node->lineNumber);

		if (checkExpressionType(node->son[1]) != dataType){
			if(checkExpressionType(node->son[1]) == DATA_TYPE_BOOL)
				fprintf(stderr, "Erro na linha %d: tipo invalido na expressao.\n", node->lineNumber);
		}
		else	
			checkEqualType(node->son[1], dataType);
	}
	}
}

void checkDataTypes(ASTREE *node) {
	if(node == 0) return;
	int i;

	// Testa atribuiçao e + com ponteiros (A = ~) ou (pt = ~)
	if (node->type == ASTREE_EQUAL){
		if (node->son[0]){
		if (node->son[0]->type == ASTREE_ADD){
			if (node->symbol->type == PONT){
				if (!checkAddPont(node->son[0], node->lineNumber))
						fprintf(stderr, "Erro na linha %d: atribuicao invalida para expressao com ponteiros.\n", node->lineNumber);
			} else if (node->symbol->type == VAR){
					if (checkAddPont(node->son[0], node->lineNumber))
						fprintf(stderr, "Erro na linha %d: tipo invalido na expressao.\n", node->lineNumber);
			}
		}
		if(node->symbol->dataType){
			checkEqualType(node, node->symbol->dataType);
		}
		}
	}

	// Teste somente para ponteiros
	if(node->type == ASTREE_ADD){
		if(node->son[0] && node->son[0]->symbol){
			if (node->son[0]->symbol->type == PONT){
				if(node->son[1] && node->son[1]->symbol)
					if (node->son[1]->symbol->type == PONT || node->son[1]->symbol->dataType == DATA_TYPE_BOOL)
						fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao aritmetica.\n", 
							node->lineNumber, node->son[1]->symbol->text);
			}
			else if  (node->son[1] && node->son[1]->symbol){	
			if (node->son[1]->symbol->type == PONT){
				if(node->son[0] && node->son[0]->symbol)
					if (node->son[0]->symbol->type == PONT || node->son[0]->symbol->dataType == DATA_TYPE_BOOL)
						fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao aritmetica.\n", 
							node->lineNumber, node->son[0]->symbol->text);			
			}
			}
		}
	}

	// Make sure the arithmetic expressions have the correct operators types
	if(node->type == ASTREE_ADD || node->type == ASTREE_SUB || node->type == ASTREE_MUL || node->type == ASTREE_DIV) {
		if(node->son[0] && node->son[0]->symbol){
			if (node->son[0]->symbol->type == PONT){
				if (node->type != ASTREE_ADD)
					fprintf(stderr, "Erro na linha %d: operador e de tipo invalido para expressao com ponteiros.\n", node->lineNumber);
			}
			if(node->son[0]->type == ASTREE_SYMBOL ||
				node->son[0]->type == ASTREE_VECTOR_ID ||
				node->son[0]->type == ASTREE_LIT_INTEGER ||
				node->son[0]->type == ASTREE_LIT_CHAR) {
				if(node->son[0]->symbol->dataType != DATA_TYPE_BYTE &&
					node->son[0]->symbol->dataType != DATA_TYPE_WORD) {
						fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao aritmetica.\n", node->lineNumber, node->son[0]->symbol->text);
				}
			}
			else fprintf(stderr, "Erro na linha %d: Operador de tipo invalido para expressao aritmetica. \n", node->lineNumber);
		}
		if (node->son[1] && node->son[1]->symbol){
			if (node->son[1]->symbol->type == PONT){
				if (node->type != ASTREE_ADD)
					fprintf(stderr, "Erro na linha %d: operador e de tipo invalido para expressao com ponteiros.\n", node->lineNumber);
			}
			if(node->son[1]->type == ASTREE_SYMBOL ||
				node->son[1]->type == ASTREE_VECTOR_ID ||
				node->son[1]->type == ASTREE_LIT_INTEGER || 
				node->son[1]->type == ASTREE_LIT_CHAR) {
				if(node->son[1]->symbol->dataType != DATA_TYPE_BYTE &&
					node->son[1]->symbol->dataType != DATA_TYPE_WORD) {
					fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao aritmetica.\n", node->lineNumber, node->son[1]->symbol->text);
				}
			}
			else fprintf(stderr, "Erro na linha %d: Operador de tipo invalido para expressao aritmetica. \n", node->lineNumber);
		}
	}

	// Make sure the relational expressions have the correct operators types
	else if(node->type == ASTREE_OP_LE || node->type == ASTREE_OP_GE || node->type == ASTREE_LESS || node->type == ASTREE_GREAT) {
		if(node->son[0]){
			if(node->son[0]->type == ASTREE_SYMBOL ||
				node->son[0]->type == ASTREE_VECTOR_ID ||
				node->son[0]->type == ASTREE_LIT_INTEGER ||
				node->son[0]->type == ASTREE_ADD ||
				node->son[0]->type == ASTREE_SUB ||
				node->son[0]->type == ASTREE_DIV ||
				node->son[0]->type == ASTREE_MUL) {
				if(node->son[0]->symbol)
				if(node->son[0]->symbol->dataType != DATA_TYPE_BYTE &&
					node->son[0]->symbol->dataType != DATA_TYPE_WORD) {
					fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao relacional.\n", node->lineNumber, node->son[0]->symbol->text);
				}
			} 
			else fprintf(stderr, "Erro na linha %d: Expressao relacional contem um operador de tipo invalido.\n", node->lineNumber);
		}
		if (node->son[1]){
			if(node->son[1]->type == ASTREE_SYMBOL ||
				node->son[1]->type == ASTREE_VECTOR_ID ||
				node->son[1]->type == ASTREE_LIT_INTEGER ||
				node->son[1]->type == ASTREE_ADD ||
				node->son[1]->type == ASTREE_SUB ||
				node->son[1]->type == ASTREE_DIV ||
				node->son[1]->type == ASTREE_MUL) {
				if(node->son[1]->symbol)
				if(node->son[1]->symbol->dataType != DATA_TYPE_BYTE &&
					node->son[1]->symbol->dataType != DATA_TYPE_WORD) {
					fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao relacional.\n", node->lineNumber, node->son[1]->symbol->text);
				}
			}
			else fprintf(stderr, "Erro na linha %d: Expressao relacional contem um operador de tipo invalido.\n", node->lineNumber);
		}
	}
	// Make sure the logical expressions have the correct operators types
	else if(node->type == ASTREE_OP_AND || node->type == ASTREE_OP_OR) {
		if(node->son[0]){
			if(node->son[0]->type == ASTREE_SYMBOL ||
				node->son[0]->type == ASTREE_VECTOR_ID ||
				node->son[0]->type == ASTREE_LIT_TRUE ||
				node->son[0]->type == ASTREE_LIT_FALSE ) {
				if(node->son[0]->symbol->dataType != DATA_TYPE_BOOL) {
					fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao logica.\n", node->lineNumber, node->son[0]->symbol->text);
				}
			}
			else fprintf(stderr, "Erro na linha %d: Expressao logica contem um operador de tipo invalido.\n", node->lineNumber);
		}
		if (node->son[1]){
			if(node->son[1]->type == ASTREE_SYMBOL ||
				node->son[1]->type == ASTREE_VECTOR_ID ||
				node->son[1]->type == ASTREE_LIT_TRUE ||
				node->son[1]->type == ASTREE_LIT_FALSE ) {
				if(node->son[1]->symbol->dataType != DATA_TYPE_BOOL) {
					fprintf(stderr, "Erro na linha %d: operador %s e de tipo invalido para expressao.\n", node->lineNumber, node->son[1]->symbol->text);
				}
			}
			else fprintf(stderr, "Erro na linha %d: Expressao logica contem um operador de tipo invalido.\n", node->lineNumber);
		}	
	}

	// Ve se o indice do vetor esta certo
	if(node->type == ASTREE_VECTOR_ID || node->type == ASTREE_EQUAL_VEC) {
		if (node->son[0]){
		if (node->son[0]->symbol->type == PONT)
			fprintf(stderr, "Erro na linha %d: index %s nao e de tipo um tipo valido.\n", node->lineNumber, node->son[0]->symbol->text);
		if(node->son[0]->symbol->dataType != DATA_TYPE_BYTE &&
			node->son[0]->symbol->dataType != DATA_TYPE_WORD) {
				fprintf(stderr,"Erro na linha %d: index %s nao e de tipo um tipo valido.\n", node->lineNumber, node->son[0]->symbol->text);
			}
		}
	}

	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDataTypes(node->son[i]);
	}
}
*/
