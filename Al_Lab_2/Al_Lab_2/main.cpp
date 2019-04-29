#include<iostream>
#include "Graph.h"


int main(void) {

	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.printAdj();
	g.deleteVertex(2);
	g.printAdj();
	g.deleteEdge(0, 1);
	g.printAdj;


	return 0;
}