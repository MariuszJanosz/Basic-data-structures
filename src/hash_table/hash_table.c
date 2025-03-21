#include <stdlib.h>
#include <stdio.h>

#include "hash_table.h"
#include "../linked_lists/linked_list/linked_list.h"

void HashTableInitialize(HashTable* hashtable, size_t size)
{
	if (size == 0) exit(1);
	hashtable->size = size;
	hashtable->table = (LinkedList**)calloc(size, sizeof(LinkedList*));
	if (!hashtable->table) exit(1);
}

void HashTableFree(HashTable* hashtable)
{
	HashTableEmpty(hashtable);
	free(hashtable->table);
}

size_t HashTableHashFunction(HashTable* hashtable, int key)
{
	key = key % hashtable->size;
	if (key < 0) key += 8;
	return key;
}

void HashTableInsert(HashTable* hashtable, int key)
{
	size_t hash = HashTableHashFunction(hashtable, key);
	if (hashtable->table[hash])
	{
		LinkedList* element = LinkedListFindKey(hashtable->table[hash], key);
		if (element) return;
	}
	hashtable->table[hash] = LinkedListInsertAtBeginning(hashtable->table[hash], key);
}

void HashTableDelet(HashTable* hashtable, int key)
{
	size_t hash = HashTableHashFunction(hashtable, key);
	LinkedList* element = LinkedListFindKey(hashtable->table[hash], key);
	hashtable->table[hash] = LinkedListRemoveElement(hashtable->table[hash], element);
}

void HashTableEmpty(HashTable* hashtable)
{
	for (size_t i = 0; i < hashtable->size; ++i)
	{
		hashtable->table[i] = LinkedListEmpty(hashtable->table[i]);
	}
}

int HashTableIsPresent(HashTable* hashtable, int key)
{
	size_t hash = HashTableHashFunction(hashtable, key);
	LinkedList* element = LinkedListFindKey(hashtable->table[hash], key);
	if (element) return 1;
	return 0;
}

void HashTablePrint(HashTable* hashtable)
{
	for (size_t i = 0; i < hashtable->size; ++i)
	{
		printf("%llu|", i);
		LinkedListPrint(hashtable->table[i]);
	}
}
