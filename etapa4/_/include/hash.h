#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAXSIZE	3209

typedef struct shash_t {
    char *text;
    int type;
    struct shash_t *next;
} hash_t;

typedef struct {
    hash_t *hashArray[MAXSIZE + 1];
} HASH_TABLE;

int hashInit(HASH_TABLE *table);

int hashDestroy(HASH_TABLE *table);

hash_t *hashInsert(HASH_TABLE *table, int type, char *text);

void hashPrint(HASH_TABLE *table);

hash_t *hashSeek(HASH_TABLE *table, int type, char *text);

#endif
