#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define TABLE_SIZE 32768
#define MAX_LAST_NAME_SIZE 16
#define OPT

/* original version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
	struct pData *data;
} entry;

typedef struct phonebook_data {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} pData;

typedef struct HASH_TABLE {
	unsigned int tableSize;
	entry **hashEntry;
} hashTable;

hashTable *initHashTable(unsigned int size);
size_t hash(char *lastName, hashTable *ht);
entry *findName(char lastname[], hashTable *ht);
entry *append(char lastName[], hashTable *ht);

#endif
