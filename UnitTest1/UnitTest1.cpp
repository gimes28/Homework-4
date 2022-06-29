#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include "../Homework 4/HashTable.h"
#include "../Homework 4/BinaryTree.h"
#include "../Homework 4/Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			HashTable hash;
			BinaryTree<int> tree;

			int numInputs = 50;
			int randNum;
			int rndNums[100];

			for (int i = 0; i < numInputs; i++) {
				rndNums[i] = i + 1;
			}

			int seed = 54;
			shuffle(rndNums, rndNums + 100, default_random_engine(seed));

			for (int i = 0; i < numInputs; i++) {
				int* treeNum = new int(rndNums[i]);
				cout << "Random Number: " << rndNums[i] << endl;
				try {
					hash.InsertItem(rndNums[i]);
					tree.Insert(treeNum);
				}
				catch (Exception e) {
					e.printError();
				}
				try {
					if (hash.FindItem(rndNums[i]) != 0) {
						cout << "Trial: " << i + 1 << " --Successfully Got item from Hash Table.--" << endl;
					}
					else {
						cout << "Trial: " << i + 1 << " --Item not found in Linear Hash Table--" << endl;
					}
					if (tree.Find(treeNum, tree.head) != nullptr) {
						cout << "Trial: " << i + 1 << " --Successfully Got item from BST.--" << endl;
					}
					else {
						cout << "Trial: " << i + 1 << " --Item not found in BST--" << endl;
					}
				}
				catch (Exception e) {
					e.printError();
				}

			}
		}
		TEST_METHOD(TestMethod2)
		{
			HashTable hash;
			BinaryTree<int> tree;

			int numInputs = 200;
			int randNum;
			int rndNums[400];

			for (int i = 0; i < numInputs; i++) {
				rndNums[i] = i + 1;
			}

			int seed = 54;
			shuffle(rndNums, rndNums + 100, default_random_engine(seed));

			for (int i = 0; i < numInputs; i++) {
				int* treeNum = new int(rndNums[i]);
				cout << "Random Number: " << rndNums[i] << endl;
				try {
					hash.InsertItem(rndNums[i]);
					tree.Insert(treeNum);
				}
				catch (Exception e) {
					e.printError();
				}
				try {
					if (hash.FindItem(rndNums[i]) != 0) {
						cout << "Trial: " << i + 1 << " --Successfully Got item from Hash Table.--" << endl;
					}
					else {
						cout << "Trial: " << i + 1 << " --Item not found in Linear Hash Table--" << endl;
					}
					if (tree.Find(treeNum, tree.head) != nullptr) {
						cout << "Trial: " << i + 1 << " --Successfully Got item from BST.--" << endl;
					}
					else {
						cout << "Trial: " << i + 1 << " --Item not found in BST--" << endl;
					}
				}
				catch (Exception e) {
					e.printError();
				}
			}
		}
	};
}
