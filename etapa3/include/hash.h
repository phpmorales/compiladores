#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAXSIZE	3209

typedef struct sHASH_NODE {
    char *text;
    int type;
    struct sHASH_NODE *next;
} HASH_NODE;

typedef struct {
    HASH_NODE *hashArray[MAXSIZE+1];
} HASH_TABLE;

int hashInit(HASH_TABLE *table);

int hashDestroy(HASH_TABLE *table);

HASH_NODE *hashInsert(HASH_TABLE *table, int type, char *text);

void hashPrint(HASH_TABLE *table);

HASH_NODE *hashSeek(HASH_TABLE *table, int type, char *text);

#endif
