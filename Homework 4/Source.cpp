#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include "HashTable.h"
#include "BinaryTree.h"

int main() {
	srand(time(NULL));

	HashTable hash;
	BinaryTree<int> tree;

	//int sel = 0;
	bool quit = false;
	int numInputs = 50;
	int randNum;
	int rndNums[100];

	for (int i = 0; i < 100; i++) {
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

	cout << "\n --Number of comparisons for Insert-- " << endl << "Hash: " << hash.GetInsertComp();
	cout << "\tBST: " << tree.GetInsertComp() << endl;
	cout << "\n --Number of comparisons for Find-- " << endl << "Hash: " << hash.GetFindComp();
	cout << "\tBST: " << tree.GetFindComp() << endl << endl;

	for (int i = 0; i < numInputs; i++) {
		try {
			if (i % 7 == 0) {
				hash.RemoveItem(rndNums[i]);
				cout << "Trial: " << i + 1 << " --Successfully removed item from Hash Table.--" << endl;
				int* num = new int(rndNums[i]);
				tree.Remove(tree.Find(num, tree.head));
				cout << "Trial: " << i + 1 << " --Successfully removed item from BST.--" << endl << endl;
			}
		}
		catch (Exception e) {
			e.printError();
		}
	}

	cout << "\n --Number of comparisons for Remove after removing index % 7 == 0 -- " << endl << "Hash: " << hash.GetRemComp();
	cout << "\tBST: " << tree.GetRemComp() << endl << endl;

	for (int i = 50; i < 100; i++) {
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

	cout << "\n --Number of comparisons for Insert-- " << endl << "Hash: " << hash.GetInsertComp();
	cout << "\tBST: " << tree.GetInsertComp() << endl;
	cout << "\n --Number of comparisons for Find-- " << endl << "Hash: " << hash.GetFindComp();
	cout << "\tBST: " << tree.GetFindComp() << endl << endl;

	for (int i = 0; i < 100; i++) {
		try {
			if (i % 9 == 0) {
				hash.FindItem(rndNums[i]);
				cout << "Trial: " << i + 1 << " --Successfully removed item from Hash Table.--" << endl;
				int* num = new int(rndNums[i]);
				tree.Find(num, tree.head);
				cout << "Trial: " << i + 1 << " --Successfully removed item from BST.--" << endl << endl;
			}
		}
		catch (Exception e) {
			e.printError();
		}
	}

	cout << "\n --Number of comparisons for Find after finding all indexes % 9 == 0 -- " << endl << "Hash: " << hash.GetFindComp();
	cout << "\tBST: " << tree.GetFindComp() << endl << endl;


	//cout << "\n --Number of comparisons for Remove-- " << endl << "Hash: " << hash.GetRemComp();
	//cout << "\tBST: " << tree.GetRemComp() << endl;
}