#include <stdlib.h>
#include <string.h>
#include "phonebook_opt.h"

hashTable *initHashTable(unsigned int size)
{
	hashTable *ht = NULL;
	ht = (hashTable*)malloc(sizeof(hashTable));
	if(ht==NULL)
		return NULL;

	ht->hashEntry = (entry**)malloc(sizeof(entry*)*size);
	if(ht->hashEntry==NULL)
	return NULL;

	for(int i = 0;i<size;i++)
	{
		ht->hashEntry[i] = NULL;
	}

	ht->tableSize = size;
	return ht;
}

size_t hash(char *lastName, hashTable *ht)
{
	size_t val = 0;
	while(*lastName != '\0')
		val += *lastName++;
	return val % ht->tableSize;
}

entry *findName(char lastName[], hashTable *ht)
{
    entry *tmp;
	size_t key = hash(lastName, ht);
	for(tmp = ht->hashEntry[key]; tmp!=NULL; tmp = tmp->pNext){
		if(strcasecmp(lastName, tmp->lastName)==0)
		{
			return tmp;
		}
	}
	return NULL;
}

entry *append(char lastName[], hashTable *ht)
{
	size_t key = hash(lastName, ht);
	entry *newEntry = (entry*)malloc(sizeof(entry));
	if(newEntry == NULL)
		return NULL;
	
	strcpy(newEntry->lastName, lastName);
	newEntry->pNext = ht->hashEntry[key];
	ht->hashEntry[key] = newEntry;
    return newEntry;
}
