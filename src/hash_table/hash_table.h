#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

#include "../linked_lists/linked_list/linked_list.h"

typedef struct HashTable
{
	size_t size;
	LinkedList** table;
}HashTable;

void HashTableInitialize(HashTable* hashtable, size_t size);
void HashTableFree(HashTable* hashtable);

size_t HashTableHashFunction(HashTable* hashtable, int key);

void HashTableInsert(HashTable* hashtable, int key);

void HashTableDelet(HashTable* hashtable, int key);
void HashTableEmpty(HashTable* hashtable);

int HashTableIsPresent(HashTable* hashtable, int key);

void HashTablePrint(HashTable* hashtable);

#endif
