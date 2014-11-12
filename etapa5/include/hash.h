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
 * hash.h
 * 
 * Funções públicas do módulo hash. Verifique a implementação para
 * maiores detalhes de como utilizar cada uma. 
 * 
 */

#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE	3209

#define SYMBOL_UNDEFINED 	0
#define SYMBOL_LIT_INTEGER 	1
#define SYMBOL_LIT_FLOATING	2
#define SYMBOL_LIT_TRUE		3
#define SYMBOL_LIT_FALSE	4
#define SYMBOL_LIT_CHAR		5
#define SYMBOL_LIT_STRING	6
#define SYMBOL_IDENTIFIER	7

#define SYMBOL_SCALAR 		8
#define SYMBOL_VECTOR 		9
#define SYMBOL_FUNCTION 	10
#define SYMBOL_POINTER 		11
#define SYMBOL_LABEL 		12

#define DATATYPE_WORD 1
#define DATATYPE_BYTE 2
#define DATATYPE_BOOL 3

typedef struct shash_t {
	char *text;
	int  type;
	int  dataType;	    //new dataType
	int  lineNumber;	//semantic error line
	int  intVal;
	char charVal;
	int  boolVal;

    struct shash_t *next;
    struct ast_t *ast;
} hash_t;

typedef struct {
    hash_t *hashArray[HASH_SIZE + 1];
} HASH_TABLE;

/***************************************
 * Function: hashInit
 * Description:
 * Input:
 * Output:
 ***************************************/
int hashInit(HASH_TABLE *table);

/***************************************
 * Function: hashDestroy
 * Description:
 * Input:
 * Output:
 ***************************************/
int hashDestroy(HASH_TABLE *table);

/***************************************
 * Function: hashInsert
 * Description:
 * Input:
 * Output:
 ***************************************/
hash_t *hashInsert(HASH_TABLE *table, int type, char *text);

/***************************************
 * Function: hashPrint
 * Description:
 * Input:
 * Output:
 ***************************************/
void hashPrint(HASH_TABLE *table);

/***************************************
 * Function: hashSeek
 * Description:
 * Input:
 * Output:
 ***************************************/
hash_t *hashSeek(HASH_TABLE *table, int type, char *text);

/***************************************
 * Function: hashCheckNotDeclared
 * Description:
 * Input:
 * Output:
 ***************************************/
void hashCheckNotDeclared(void); 	//semantic Check

/***************************************
 * Function: makeTemp
 * Description:
 * Input:
 * Output:
 ***************************************/
hash_t *makeTemp(void);		//for TAC

/***************************************
 * Function: makeLabel
 * Description:
 * Input:
 * Output:
 ***************************************/
hash_t *makeLabel(void);		//for TAC

#endif
