#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MY_PRIME_NR	3209

typedef struct sHASH_NODE {
    char *text;
    int type;
    struct sHASH_NODE *next;
} HASH_NODE;

typedef struct {
    HASH_NODE *hashArray[MY_PRIME_NR+1];
} HASH_TABLE;

int hashInit(HASH_TABLE *table);

int hashDestroy(HASH_TABLE *table);

int hashInsert(HASH_TABLE *table, int type, char *text);

void hashPrint(HASH_TABLE *table);

HASH_NODE *hashSeek(HASH_TABLE *table, int type, char *text);

#endif
