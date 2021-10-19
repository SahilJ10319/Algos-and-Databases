#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
	HashTable ht;

	for (int i = 0; i < 23; i++) {
		ht.insert(i);
	}

	ht.insert(58);
	
	return 0;
}