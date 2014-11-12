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
 * gv.h
 * 
 * Funções públicas do módulo gv. Verifique a implementação para
 * maiores detalhes de como utilizar cada uma. 
 * 
 */

#ifndef __SEMANTIC_H__
#define __SEMANTIC_H__

#include "ast.h"

int extern semanticFlag;

/***************************************
 * Function: setDataType
 * Description:
 * Input:
 * Output:
 ***************************************/
int setDataType ( int astType );

/***************************************
 * Function: semanticDeclarationCheck
 * Description:
 * Input:
 * Output:
 ***************************************/
void semanticDeclaration ( ast_t *node );

/***************************************
 * Function: semanticUtilizationCheck
 * Description:
 * Input:
 * Output:
 ***************************************/
void semanticUtilization ( ast_t *node );

#endif
