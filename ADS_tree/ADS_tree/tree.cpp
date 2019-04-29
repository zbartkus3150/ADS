#include <iostream>
#include "tree.h"
using namespace std;
#include <list>

Node* InsertNode(int nkey, Node* tree) {
	if (tree == NULL) {
		tree = new Node(nkey);
		cout << "New tree with key [" << nkey << "] created" << endl;
		return tree;
	}
	else {
		if (tree->key > nkey) {
			if (tree->left == NULL) {
				tree->left = new Node(nkey, tree);
				cout << "Add " << nkey << " to NULL left" << endl;
				return tree->left;
			}
			else
				cout << "Move " << nkey << " to left" << endl;
				return InsertNode(nkey, tree->left);
		}
		else if (tree->key < nkey) {
			if (tree->right == NULL) {
				tree->right = new Node(nkey, tree);
				cout << "Add " << nkey << " to NULL right" << endl;
				return tree->right;
			}
			else
				cout << "Move " << nkey << " to right" << endl;
				return InsertNode(nkey, tree->right);
		}
		else {
			if (tree->mid == NULL) {
				tree->mid = new Node(nkey, tree);
				cout << "Add " << nkey << " to NULL mid" << endl;
				return tree->mid;
			}
			else
				cout << "Move " << nkey << " to mid" << endl;
				return InsertNode(nkey, tree->mid);
		}
	}
}

void Search(int skey, Node* tree) {
	if (tree == NULL) {
		cout << "Tree is empty" << endl;
		return;
	}
	list<Node*> keys;
	keys.push_back(tree);
	while (!keys.empty()) {
		if (keys.front()->key == skey) {
			cout << skey << " Found" << endl;
			return;
		}
		for (auto it = keys.begin(); it != keys.end(); it++) {
			if ((*it)->left != NULL)
				keys.push_back((*it)->left);
			if ((*it)->mid != NULL)
				keys.push_back((*it)->mid);
			if ((*it)->right != NULL)
				keys.push_back((*it)->right);
		}
		keys.pop_front();
	}
	cout << skey << " Not found" << endl;
}


void Print(Node* tree) {
	if (tree == NULL) {
		cout << "Tree is empty" << endl;
		return;
	}
	cout << "Tree: " << endl;
	list<Node*> keys;
	keys.push_back(tree);
	int counter = 1;
	int i = 0;
	cout << keys.front()->key << endl;
	while (!keys.empty()) {
		for (auto it = keys.begin(); it != keys.end(); it++) {
			if (counter == 0)
				return;
			counter--;
			if ((*it)->left != NULL) {
				keys.push_back((*it)->left);
				cout << (*it)->left->key;
				i++;
			}
			else
				cout << "N";
			if ((*it)->mid != NULL) {
				keys.push_back((*it)->mid);
				cout << (*it)->mid->key;
				i++;;
			}
			else
				cout << "N";
			if ((*it)->right != NULL) {
				keys.push_back((*it)->right);
				cout << (*it)->right->key;
				i++;
			}
			else
				cout << "N";
			cout << " ";
			if (counter == 0) {
				counter = i;
				i = 0;
				cout << endl;
			}
		}
		keys.pop_front();
	}
}