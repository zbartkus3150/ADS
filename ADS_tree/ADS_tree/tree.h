#pragma once
#include <iostream>

struct Node {
	int key;
	struct Node *left, *mid, *right, *parent;
	Node(int key, Node* parent = NULL) {
		this->key = key;
		this->parent = parent;
		this->left = this->mid = this->right = NULL;
	}
};

Node* InsertNode(int nkey, Node* tree = NULL);

void Search(int skey, Node* tree);

void Print(Node* tree);