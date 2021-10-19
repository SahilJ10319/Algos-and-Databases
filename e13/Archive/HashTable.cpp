#include "HashTable.h"
#

// Exercise 13 - complete insert method
// Use quadratic probing
// Do not insert duplicates
// Recognize insert failure due to secondary clustering
void HashTable::insert(int key)
{
	int count = 1;
	bool inserted = false;

	int index = hash(key);

	int lastIndex = -1;
	int originalIndex = index;

	while (inserted == false) {
		if (arr[index] == -1) {
			arr[index] = key;
			inserted = true;
		}
		else if (arr[index] == key) {
			break;
		}
		else {
			index = originalIndex + (count * count);
			
			index = index % maxn;
			
			if (lastIndex == index) {
				break;
			}
			lastIndex = index;
			count++;
		}
	}
}

// Constructors etc.
// Default constructor - creates hash table of size 101
HashTable::HashTable()
{
	n = 0;
	maxn = 101;
	arr = new int[maxn];
	for (int i = 0; i < maxn; i++) {
		arr[i] = -1;
	}
}

// Constructor(int)
// Underlying array of size first prime after 2*expectedn
HashTable::HashTable(int expectedn)
{
	n = 0;
	maxn = nextPrime(2 * expectedn);
	arr = new int[maxn];
	for (int i = 0; i < maxn; i++) {
		arr[i] = -1;
	}
}

// Copy constructor
HashTable::HashTable(const HashTable & ht)
{
	copyTable(ht);
}

// Destructor
HashTable::~HashTable()
{
	deleteTable();
}

// Overloaded assignment operator
HashTable & HashTable::operator=(const HashTable & ht)
{
	if (&ht != this) {
		deleteTable();
		copyTable(ht);
	}
	return *this;
}

// Returns number of values stored in hash table
int HashTable::size() const
{
	return n;
}

// Returns a copy of the hash table's underlying array
// For testing Exercise 13
int* HashTable::dump(int & resultn) const
{
	int* result = new int[maxn];
	resultn = maxn;

	for (int i = 0; i < maxn; ++i) {
		result[i] = arr[i];
	}

	return result;
}

// Helper methods
// Makes a deep copy of the parameter and assigns it to calling object
void HashTable::copyTable(const HashTable & ht)
{
	maxn = ht.maxn;
	n = ht.n;
	arr = new int[maxn];
	for (int i = 0; i < maxn; ++i) {
		if (ht.arr[i] != -1) {
			arr[i] = ht.arr[i];
		}
		else {
			arr[i] = -1;
		}
	}
}

// Deallocates dynamic memory associated with calling object
void HashTable::deleteTable()
{
	delete[] arr;
	n = 0;
	maxn = 0;
	arr = nullptr;
}

// Hash function: key mod array size
int HashTable::hash(int key) const {

	return key % maxn;
}

// Finds first prime number equal to or greater than x
int HashTable::nextPrime(int x) const {
	int result = x;
	bool isPrime = checkPrime(result);
	while (!isPrime) {
		result++;
		isPrime = checkPrime(result);
	}
	return result;
}

// Returns true iff x is prime
bool HashTable::checkPrime(int x) const {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
