#include<iostream>
#include "Graph.h"


void EulerTest(Graph &g)
{
	int res = g.isEulerian();
	if (res == 0)
		std::cout << "Graph is not Eulerian\n\n";
	else if (res == 1)
		std::cout << "Graph has an Euler path\n\n";
	else
		std::cout << "Graph has an Euler cycle and an Euler Path\n\n";
}

int main(void) {

	/*Graph g1(1);
	g1.printAdj();
	EulerTest(g1);

	Graph g2(4);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.addEdge(3, 1);
	g2.printAdj();
	EulerTest(g2);

	Graph g3(3);
	g3.addEdge(1, 2);
	g3.printAdj();
	EulerTest(g3);

	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(0, 2);
	g4.printAdj();
	EulerTest(g4);*/

	Graph g(4);
	g.addEdge(2, 3);
	g.printAdj();
	EulerTest(g);

	return 0;
}