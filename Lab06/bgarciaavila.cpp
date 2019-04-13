#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <list>
#include <sstream>

using namespace std;

int m; //hash table size, in pseudocode refers to it as var m
std::list<int> *HashTable; 

int hashFunction(int x) { //has function or key as some call it
	return x % m;
}

void ChainedHashInsert(int key) {
	HashTable[hashFunction(key)].push_front(key); //use list sti function push front
	//to skip a step of setting the hashfunction(key) to a variable I put it in within the HashTable call
}

void ChainedHashSearch(int key) {
	//Works similar to the delete function
	int count = 0;
	std::list<int>::iterator i; 

	for (i = HashTable[hashFunction(key)].begin(); i != HashTable[hashFunction(key)].end(); i++) { 
		if (*i == key)   {
			cout << key << ":FOUND_AT" << hashFunction(key) << "," << count << ";\n";
			return;
		}
		//used to give accurate location for FOUND_AT[],[]
		count++;
	}
	cout << key << ":NOT_FOUND;\n";
}

void ChainedHashDelete(int key) {
	int count = 0;
	std::list<int>::iterator i;

	for (i = HashTable[hashFunction(key)].begin(); i != HashTable[hashFunction(key)].end(); i++) { 
		if (*i == key) {
			i = HashTable[hashFunction(key)].erase(i);
			cout << key << ":DELETED;\n";
			return;
		}
		count++;
	}
	cout << key << ":DELETE_FAILED;\n";
}

void printHashTable() {
	for (int i = 0; i < m; i++) {
		cout << i << ":";
		for (auto x : HashTable[i]) {
			cout << x << "->";
		}
		cout << ";" << endl;
	}
}

int main() { 
	cin >> m;
  	HashTable = new std::list<int>[m];
  	char action;

  	while (action != 'e') {
    	int key;

    	cin >> action;
    	switch (action) {
    		case 'i':
      		cin >> key;
      		ChainedHashInsert(key);
      		break;

    	case 'd':
      		cin >> key;
      		ChainedHashDelete(key);
      		break;

    	case 's':
      		cin >> key;
      		ChainedHashSearch(key);
      		break;

    	case 'o':
      		printHashTable();
      		break;
    }
  }
}