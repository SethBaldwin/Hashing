#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <array>

const int SIZE = 11;
const int RES_TECH = 1;

template<class ItemType>
class HashTable
{
public:
	// Default constructor
	// Pre: None.
	// Post: A hash table has been made that is either empty or contains data from a file
	HashTable();
	// Destructor
	// Pre: A table exists.
	// Post: The table is destroyed.
	~HashTable();
	// Copy Constructor
	// Pre: A table exists.
	// Post: A copy of the table has been made
	HashTable(const HashTable<ItemType> &acopy);

	// Adds an item to the hash table at the hash value
	bool AddItem(ItemType, unsigned int);

	// Prints the table in a list
	void PrintTable();

	// Prints the various stats of the hash table
	void PrintStats();

	// Overwrites the txt file when an item is removed
	void OverwriteFile(std::string);

	// Get item at index
	ItemType GetItem(unsigned int); 

	// Gets the next item using the set collision resolution
	ItemType GetNextItem(unsigned int , int);

	// Returns true if the index is used. /// Not used?
	bool IsOccupied(unsigned int);

	// Removes the item passed.
	bool RemoveItem(ItemType, unsigned int);

	// Gets the number of items in the table
	int GetNumItems();


	// Handles which collision resolution technique is used
	unsigned int CollResolution(unsigned int);

	// A collision resolution technique that puts the item in the next available space
	int LinearProbing(unsigned int);

	// A collision resolution technique that puts the item in the index = the index + num_col aquared. % table size
	int QuadraticProbing(unsigned int);


	// Gets the total size of the table.
	size_t GetTableSize(){ return table_size; };

private:
	// Should be the prime number closest to 2x the amount of items you expect 
	// If changed, delete passwd.
	const size_t table_size = SIZE;

	std::vector<ItemType> hash_table;

	int collisions[SIZE];

	int num_collisions;
	int tot_collisions;
	int average_collisions;
	int num_adds;
	int num_deletes;
	int num_items;

	const int collision_res_tech = RES_TECH;
	
};

#include "HashTable.template"

#endif