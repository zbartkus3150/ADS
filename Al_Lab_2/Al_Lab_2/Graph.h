#pragma once

#include <list>

class Graph {
private:
	std::list<int> V;
	std::list<int>* adj;

public:
	Graph(int number_V);
	void addVertex(int v);
	void addEdge(int v, int w);
	void deleteVertex(int v);
	void deleteEdge(int v, int w);
	void printAdj();
};