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
 * hash.c
 * 
 * As funções deste arquivo, se corretamente utilizadas, permitem a
 * geração de uma tabela hash que conterá todos os símbolos da linguagem.
 * As funções implementadas aqui permitem realizar as seguintes operações:
 * 1. Criar uma tabela hash.
 * 2. Gerar uma posição da hash.
 * 3. Inserir um símbolo na hash.
 * 4. Posicionar o cursor em um nodo da hash.
 * 5. Destruir a tabela hash.
 * 6. Imprimir a tabela hash.
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ast.h"
#include "../include/hash.h"
#include "../include/y.tab.h"

extern int semanticFlag;
extern int getLineNumber(void);

/***************************************
 * Function: hashInit
 * Description:
 * Input:
 * Output:
 ***************************************/
int hashInit(HASH_TABLE *table) {
    int i;

    for (i = 0; i < HASH_SIZE + 1; i++) 
        table->hashArray[i] = NULL;

    return 0;
}

/***************************************
 * Function: getHashCode
 * Description:
 * Input:
 * Output:
 ***************************************/
int getHashCode(char *text) {
    int address = 1;
    int i;

    for (i = 0; text[i] != '\0'; i++)
        address = (address * text[i]) % HASH_SIZE + 1;

    return address;
}

/***************************************
 * Function: hashInsert
 * Description:
 * Input:
 * Output:
 ***************************************/
hash_t *hashInsert(HASH_TABLE *table, int type, char *text) {
    int address;
    hash_t *node, *newNode;


    // se achar
    if (hashSeek(table, type, text) != NULL) {
        //	fprintf(stderr, "hue");
        return (hashSeek(table, type, text));
    }

    address = getHashCode(text);
    node = table->hashArray[address];
    newNode = malloc(sizeof (hash_t));
    newNode->type = type;
    newNode->text = malloc(strlen(text) + 2);
    strcpy(newNode->text, text);

	newNode->intVal = 0;
    newNode->charVal = '\0';
    newNode->boolVal = 0;
	newNode->dataType  = 0;
    newNode->ast = 0;
	newNode->lineNumber = getLineNumber(); //semantic line error
	
	switch (type) {
        case SYMBOL_LIT_INTEGER:
            newNode->intVal = atoi(text);
            break;
		case SYMBOL_LIT_CHAR:
		    newNode->charVal = text[1];
		    break;
		case SYMBOL_LIT_TRUE:
		    newNode->boolVal = 1;
		    break;
		case SYMBOL_LIT_FALSE:
		    newNode->boolVal = 0;
		    break;
		default:
		    break;
   	}

    newNode->next = node;
    table->hashArray[address] = newNode;

    return newNode;
}

/***************************************
 * Function: hashSeek
 * Description:
 * Input:
 * Output:
 ***************************************/
hash_t *hashSeek(HASH_TABLE *table, int type, char *text) {
    hash_t *node;
    int address, found = 0;

    address = getHashCode(text);
    node = table->hashArray[address];

    while ((found == 0) && node != NULL) {
        if (node->type == type && (strcmp(node->text, text) == 0))
            found = 1;
        else
            node = node->next;
    }

    if (found)
        return node;
    else
        return 0;
}

/***************************************
 * Function: hashDestroy
 * Description:
 * Input:
 * Output:
 ***************************************/
int hashDestroy(HASH_TABLE *table) {
    int i;
    hash_t *node;

    for (i = 0; i < HASH_SIZE + 1; i++) {
        for (node = table->hashArray[i]; node != NULL; node = node->next) {
            free(node);
        }
        table->hashArray[i] = NULL;
    }
    return 0;
}

/***************************************
 * Function: hashPrint
 * Description:
 * Input:
 * Output:
 ***************************************/
void hashPrint(HASH_TABLE *table) {
    int i;
    hash_t *node;

    //printf("\n-----------------------------------------");
    //printf("\nNOW, THE HASH TABLE WILL BE SHOWN");
    //printf("\n-----------------------------------------\n");

    for (i = 0; i < HASH_SIZE + 1; i++) {
        for (node = table->hashArray[i]; node != NULL; node = node->next) {
            switch (node->type) {
                case SYMBOL_LIT_TRUE:
                    //printf("POSITION:[%d] - TYPE: [LIT TRUE] - VALUE: [%s] \n", i, node->text);
                    break;
                case SYMBOL_LIT_FALSE:
                    //printf("POSITION:[%d] - TYPE: [LIT FALSE] - VALUE: [%s] \n", i, node->text);
                    break;
                case SYMBOL_LIT_INTEGER:
                    //printf("POSITION:[%d] - TYPE: [INT] - VALUE: [%s] \n", i, node->text);
                    break;
                case SYMBOL_LIT_CHAR:
                    //printf("POSITION:[%d] - TYPE: [CHAR] - VALUE: [%s] \n", i, node->text);
                    break;
                case SYMBOL_LIT_STRING:
                    //printf("POSITION:[%d] - TYPE: [STRING] - VALUE: [%s] \n", i, node->text);
                    break;
                default:
                    //printf("POSITION:[%d] - IDENTIFIER: [%s] \n", i, node->text);
                    break;
            }
        }
    }
    printf("-----------------------------------------");
    printf("\nEND OF HASH TABLE");
    printf("\n-----------------------------------------\n");
}
