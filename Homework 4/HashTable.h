#pragma once
#ifndef HASHTABLE_h
#define HASHTABLE_h
#include <iostream>
#include "Exception.h"
using namespace std;

class HashTable {
private:
    int values[500];
    int length = 0;
    int size = 500;
    int Hash(int hashVal);
    int insCompCount = 1;
    int findCompCount = 1;
    int remCompCount = 1;
public:
    HashTable();
    ~HashTable();
    int InsertItem(int val);
    int RemoveItem(int val);
    int FindItem(int val);
    int GetLength();
    void Print();
    int GetInsertComp();
    int GetFindComp();
    int GetRemComp();
};

int HashTable::Hash(int hashVal) {
    return hashVal % (size - length);
}

HashTable::HashTable() {// default 
    for (int i = 0; i < size; i++) {
        values[i] = 0;
    }
}

HashTable::~HashTable() { //Destructor
    for (int i = 0; i < size; i++) {
        values[i] = 0;
    }
    length = 0;
}

int HashTable::InsertItem(int val) {
    if (length >= size) {
        throw(Exception("HashTable is full"));
    }
    int spot = Hash(val);
    while (values[spot] != 0) {
        spot = (spot + 1) % size;
        insCompCount++;
    }
    insCompCount++;
    values[spot] = val;
    length++;
}
int HashTable::RemoveItem(int val) {
    if (length <= 0) {
        throw(Exception("HashTable is empty"));
    }
    int spot = Hash(val);
    int retval = values[spot];
    if (retval == 0) {
        return retval;
    }
    values[spot] = 0;
    remCompCount++;
    length--;
    return retval;
}

int HashTable::FindItem(int val) {
    if (length <= 0) {
        throw(Exception("HashTable is empty"));
    }
    int spot = Hash(val);
    while (values[spot] != 0 && values[spot] != val) {
        findCompCount++;
        spot = (spot + 1) % size;
    }
    if (values[spot] == 0) {
        findCompCount++;
        return 0;
    }
    findCompCount++;
    return values[spot];
}

int HashTable::GetLength() {
    return length;
}

void HashTable::Print() {
    for (int i = 0; i < size; ++i) {
        if (values[i] == 0) {
            cout << "Empty" << endl;
        }
        else {
            cout << values[i] << endl;
        }
    }
}

int HashTable::GetFindComp() {
    return findCompCount;
}

int HashTable::GetInsertComp() {
    return insCompCount;
}

int HashTable::GetRemComp() {
    return remCompCount;
}

#endif