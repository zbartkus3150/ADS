#include "tree.h"

void main() {
	Node* tree = InsertNode(5);
	InsertNode(4, tree);
	InsertNode(3, tree);
	Search(2, tree);
	Print(tree);
}