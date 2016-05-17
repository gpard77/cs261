/***********************************************
 * Geoffrey Pard
 * CS261 - 400
 * Assignment 6
 **********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	/*write this*/	
	hashLink * cur, * temp;

	for (int i = 0; i < ht->tableSize; i++)
	{
	   cur = ht->table[i];
	   while (cur != NULL)
	   {
	      temp = cur->next;
	      cur->key = 0;
	      cur->value = 0;
	      free(cur);
	      //ht->count--;
	      cur = temp;
	   }
	   ht->table[i] = NULL;
  	}

	// Free the Table; Reset Values
	free(ht->table);
	ht->tableSize = 0;
	ht->count = 0;	
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/
	struct hashMap * newMap, * oldMap;
	hashLink * cur, * temp; 

	// Re-initialize to appropriate size; Load values
	newMap = createMap(newTableSize);
	oldMap = ht;

	for (int i = 0; i < ht->tableSize; i++)
	{
	   cur = ht->table[i]; 
	   while (cur != 0)
	   {
	      insertMap(newMap, cur->key, cur->value);
	      temp = cur;
	      cur = cur->next;
	      free(temp);
	   }
	}
	//_freeMap(oldMap);

	ht->table = newMap->table;
	ht->tableSize = newMap->tableSize;
	ht->count = newMap->count;
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	/*write this*/
	
	//Check load factor
	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
	{
	   _setTableSize(ht, (2 * (ht->tableSize)));
	}

	// Create new hash link and Init
	hashLink *newHashLink = malloc(sizeof(hashLink));
	assert(newHashLink != 0);
	
	newHashLink->value = v;
	newHashLink->key = k;
	newHashLink->next = NULL;

	// Check contains: remove and free if necessary
	if (containsKey(ht, k)== 1)  // True
	{
	   removeKey(ht, k);
	}
	
	// Mod using provided functions
	//int sub1 = stringHash1(k) % ht->tableSize;
	int sub2 = stringHash2(k) % ht->tableSize; 

	// Use one of the hashing functions to dictate
	// a subscript; first, check to see if available.
	// If not, move on.
	if (ht->table[sub2] == NULL) // Empty--stick it here.
	{
	   ht->table[sub2] = newHashLink;
	}
	else
	{
	   //create temp link to probe
	   hashLink * temp = ht->table[sub2];
	   while (temp->next != 0)
	   {
	      temp = temp->next;
	   }
	   // Out of loop: found our spot
	   temp->next = newHashLink;
	}

	// Grow Size
	ht->count++;

}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 
	/*write this*/

	// Mod using provided functions
	//int sub1 = stringHash1(k) % ht->tableSize;
	int sub2 = stringHash2(k) % ht->tableSize; 

	// Temp link for searching
	hashLink * temp = ht->table[sub2];
		
	while (strcmp(temp->key, k) != 0)
	{
	   temp = temp->next;
	}

	return &temp->value;
	
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/

	// Mod using provided functions
	//int sub1 = stringHash1(k) % ht->tableSize;
	int sub2 = stringHash2(k) % ht->tableSize;

	hashLink * temp = ht->table[sub2];

	if (sub2 < 0)
	{
	   sub2 += ht->tableSize;
	}

	while (temp != NULL)
	{
	   if (strcmp(temp->key, k) == 0)
	   {
	      return 1; //True, Found
	   }
	   temp = temp->next; // Moving on...still searching
	}
 
	return 0; // Not found
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/	

	// Mod using provided functions
	//int sub1 = stringHash1(k) % ht->tableSize;
	int sub2 = stringHash2(k) % ht->tableSize;

	hashLink * cur, * temp;
	
	temp = cur = ht->table[sub2];
	
	while (cur != NULL)
	{
	   if (strcmp(cur->key, k) == 0)
	   {
	      if (cur == ht->table[sub2])
	      {
 	         ht->table[sub2] = cur->next;
	      }
	      else
	      {
		 temp->next = cur->next;
	      }
	      free(cur);
	      ht->count--;
              return;
	   }
	   temp = cur;
	   cur = temp->next;
	}
	
	// Never Found
	printf("Key Not Found. Nothing Removed.\n"); 
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	/*write this*/
	return ht->count;	
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	/*write this*/
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	/*write this*/
	int counter = 0;

	for (int i = 0; i < ht->tableSize; i++)
	{
	   if (ht->table[i] == 0)
	   {
	      counter++;
	   }
	}
	return counter;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	/*write this*/
	float load = 0;

	load = (float)size(ht)/capacity(ht);

	return load;
}
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}