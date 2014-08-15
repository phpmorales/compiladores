#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "tokens.h"

int hashInit(HASH_TABLE *table) {
    int i;
    for (i = 0; i < MY_PRIME_NR+1; i++)
        table->hashArray[i] = NULL;
        
    return 0;
}

int getHashCode(char *text) {
    int address = 1;
    int i;
    
    for (i = 0; text[i] != '\0'; i++) {
        address = (address * text[i]) % MY_PRIME_NR +  1;
    }
    return address;
}

int hashInsert(HASH_TABLE *table, int type, char *text) {
	int address;
	HASH_NODE *node, *newNode;
	

	// se achar
	if(hashSeek(table,type,text)!=NULL)
		return -1;

	address = getHashCode(text);
	node = table->hashArray[address];
	newNode = malloc(sizeof(HASH_NODE));
	newNode->type = type;
	newNode->text = malloc(strlen(text)+2);
	strcpy(newNode->text, text);

 	newNode->next = node;
	table->hashArray[address] = newNode;
  
	return 0;    
}

HASH_NODE *hashSeek(HASH_TABLE *table, int type, char *text) {
	HASH_NODE *node;
	int address, found=0;

	address = getHashCode(text);
	node = table->hashArray[address];

	while((found==0) && node!=NULL)
	{
		if(node->type==type && (strcmp(node->text,text)==0))
			found=1;
		else
			node=node->next;
	}

	if(found)
		return node;
	else
		return 0;
}  

int hashDestroy(HASH_TABLE *table) {
    int i;
    HASH_NODE *node;
    
    for (i = 0; i < MY_PRIME_NR+1; i++) {
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
    
    for (i = 0; i < MY_PRIME_NR+1; i++) {
        for (node = table->hashArray[i]; node != NULL; node = node->next) {
		switch(node->type)
		{
			case LIT_TRUE: 		printf("\nPos:[%d] - Tipo: LIT TRUE Valor: %s ",i , node->text);
				break;
			case LIT_FALSE: 	printf("\nPos:[%d] - Tipo: LIT FALSE Valor: %s ",i , node->text);
				break;
			case LIT_INTEGER: 	printf("\nPos:[%d] - Tipo: INT Valor: %s ",i , node->text);
				break;
			case LIT_CHAR:		printf("\nPos:[%d] - Tipo: CHAR Valor: %s ",i ,  node->text);
				break;
			case LIT_STRING:	printf("\nPos:[%d] - Tipo: STRING Valor: %s ",i ,  node->text);
				break;
			default:		printf("\nPos:[%d] - Identifier: %s ",i ,  node->text);
				break;
		}
        }
    }        
}