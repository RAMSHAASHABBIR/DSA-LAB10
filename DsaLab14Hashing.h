#pragma once
#include<iostream>
#include <vector>
#include<list>
#include <unordered_map>
using namespace std;
//     Chaining method
int hashFunction(int key, int tableSize = 5) {
	return key % tableSize;
}
void insert(int key, const string& value, vector<list<pair<int, string>>>& table) {
	int index = hashFunction(key);
	table[index].push_back(make_pair(key, value));
}
void printHashTable(vector<list<pair<int, string>>>& hashTable) {
	for (int i = 0; i < 5; ++i) {
		std::cout << "Index " << i << ": ";
		for (const auto& pair : hashTable[i]) {
			cout << "[" << pair.first << ", " << pair.second << "] ";
		}
		cout << endl;
	}
}

//      Linear probing
void insertProbing(int key, const string& value, vector<pair<int, string>>& table) {
	int index = hashFunction(key);
	int i = 0;
	while (table[index].first != -1) {
		index = (index + i) % 5;
		i++;
	}
	table[index] = make_pair(key, value);
}
void printLinearProbingTable(vector<pair<int, string>>& table) {
	for (int i = 0; i < 5; ++i) {
		cout << "Index " << i << ": ";
		if (table[i].first != -1) {
			cout << "[" << table[i].first << ", " << table[i].second << "] ";
		}
		cout << endl;
	}
}
//     Quadratic Probing
void insertQuadratic(int key, const string& value, vector<pair<int, string>>& table) {
	int index = hashFunction(key, table.size());
	int i = 0;
	while (table[index].first != -1) {
		index = (index + i * i) % table.size();
		i++;
	}
	table[index] = make_pair(key, value);
}
