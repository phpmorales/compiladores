/*
 *
 * Author: Miller Biazus
 *		   Pedro Henrique Pinto Morales
 * UFRGS - Instituto de Informática
 * Etapa 5 - Compiladores - Prof. Marcelo de Oliveira Johann
 * 2014/2
 *
 */

#ifndef __TAC_HEADER__
#define __TAC_HEADER__

#include "hash.h"
#include "ast.h"

#define TAC_ADD 	    1
#define TAC_SUB		    2
#define TAC_MUL 	    3
#define TAC_DIV 	    4

#define TAC_DATAINT 	5 
#define TAC_DATABOOL 	7

#define TAC_INTEGER     9 
#define TAC_BOOLEAN     11
#define TAC_CHARACTER   12
#define TAC_STRING 	    13

#define TAC_INPUT       14
#define TAC_OUTPUT      15
#define TAC_RETURN      16

#define TAC_LE 		    17
#define TAC_GE 		    18
#define TAC_EQ 		    19
#define TAC_NE 		    20
#define TAC_AND 	    21
#define TAC_OR 		    22

//#define TAC_IGUAL	    23
#define TAC_MOV		    23
#define TAC_MOV_VET	    24
#define TAC_MAIOR	    25
#define TAC_MENOR   	26
#define TAC_LABEL	    27
#define TAC_BEGINFUN	28
#define TAC_ENDFUN	    29
#define TAC_CALL	    30
#define TAC_JUMP	    31
#define TAC_VETOR	    32
#define TAC_VARIABLE	33
#define TAC_JFALSE	    34
#define TAC_SALTO	    35
#define TAC_DECLARE 	36
#define TAC_DECLAREVET	37
#define TAC_LISTAPARAM	38
#define TAC_PARAMETRO	39
#define TAC_DEC_POINTER 40
#define TAC_VAR_VET	    41

typedef struct tac_structure{
	int type; //operaçao
	hash_t *target;
	hash_t *op1;
	hash_t *op2;

	struct tac_structure* prev;
	struct tac_structure* next;
} tac_t ;

/***************************************
 * Function: tacCreate
 * Description:
 * Input:
 * Output:
 ***************************************/
tac_t* tacCreate(int type, hash_t *target, hash_t *op1, hash_t *op2);

/***************************************
 * Function: makeBinOp
 * Description:
 * Input:
 * Output:
 ***************************************/
tac_t* makeBinOp(tac_t *code0, tac_t *code1,int type);

/***************************************
 * Function: tacJoin
 * Description:
 * Input:
 * Output:
 ***************************************/
tac_t* tacJoin(tac_t* l1, tac_t* l2); 

/***************************************
 * Function: tacCodeGen
 * Description:
 * Input:
 * Output:
 ***************************************/
tac_t* tacCodeGen(ast_t* root);

/***************************************
 * Function: tacReverse
 * Description:
 * Input:
 * Output:
 ***************************************/
tac_t *tacReverse(tac_t *last);

/***************************************
 * Function: tacPrintList
 * Description:
 * Input:
 * Output:
 ***************************************/
void tacPrintList(tac_t* tac);

/***************************************
 * Function: tacPrintSingle
 * Description:
 * Input:
 * Output:
 ***************************************/
void tacPrintSingle(tac_t* tac);

#endif
