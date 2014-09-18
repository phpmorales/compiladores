#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"
#include "../include/hash.h"
#include "../include/tokens.h"

int hashInit(HASH_TABLE *table) {
    int i;

    for (i = 0; i < MAXSIZE + 1; i++) 
        table->hashArray[i] = NULL;

    return 0;
}

int getHashCode(char *text) {
    int address = 1;
    int i;

    for (i = 0; text[i] != '\0'; i++)
        address = (address * text[i]) % MAXSIZE + 1;

    return address;
}

HASH_NODE *hashInsert(HASH_TABLE *table, int type, char *text) {
    int address;
    HASH_NODE *node, *newNode;


    // se achar
    if (hashSeek(table, type, text) != NULL) {
        //	fprintf(stderr, "hue");
        return (hashSeek(table, type, text));
    }

    address = getHashCode(text);
    node = table->hashArray[address];
    newNode = malloc(sizeof (HASH_NODE));
    newNode->type = type;
    newNode->text = malloc(strlen(text) + 2);
    strcpy(newNode->text, text);

    newNode->next = node;
    table->hashArray[address] = newNode;

    return newNode;
}

HASH_NODE *hashSeek(HASH_TABLE *table, int type, char *text) {
    HASH_NODE *node;
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

int hashDestroy(HASH_TABLE *table) {
    int i;
    HASH_NODE *node;

    for (i = 0; i < MAXSIZE + 1; i++) {
        for (node = table->hashArray[i]; node != NULL; node = node->next) {
            free(node);
        }
        table->hashArray[i] = NULL;
    }
    return 0;
}

void hashPrint(HASH_TABLE *table) {
    int i;
    HASH_NODE *node;

    printf("\n-----------------------------------------");
    printf("\nNOW, THE HASH TABLE WILL BE SHOWN");
    printf("\n-----------------------------------------\n");

    for (i = 0; i < MAXSIZE + 1; i++) {
        for (node = table->hashArray[i]; node != NULL; node = node->next) {
            switch (node->type) {
                case LIT_TRUE:
                    printf("POSITION:[%d] - TYPE: [LIT TRUE] - VALUE: [%s] \n", i, node->text);
                    break;
                case LIT_FALSE:
                    printf("POSITION:[%d] - TYPE: [LIT FALSE] - VALUE: [%s] \n", i, node->text);
                    break;
                case LIT_INTEGER:
                    printf("POSITION:[%d] - TYPE: [INT] - VALUE: [%s] \n", i, node->text);
                    break;
                case LIT_CHAR:
                    printf("POSITION:[%d] - TYPE: [CHAR] - VALUE: [%s] \n", i, node->text);
                    break;
                case LIT_STRING:
                    printf("POSITION:[%d] - TYPE: [STRING] - VALUE: [%s] \n", i, node->text);
                    break;
                default:
                    printf("POSITION:[%d] - IDENTIFIER: [%s] \n", i, node->text);
                    break;
            }
        }
    }
    printf("-----------------------------------------");
    printf("\nEND OF HASH TABLE");
    printf("\n-----------------------------------------\n");
}
