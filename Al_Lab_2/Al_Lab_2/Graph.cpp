#include "Graph.h"
#include <iostream>

Graph::Graph(int number_V) {
	for (int i = 0; i < number_V; i++)
		V.push_back(i);
	adj = new std::list<int>[1024];
}

void Graph::addVertex(int v) {
	V.push_back(v);
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::deleteVertex(int v) {
	for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
		adj[*it].remove(v);
	}
	adj[v].erase(adj[v].begin(), adj[v].end());
	V.remove(v);
}

void Graph::deleteEdge(int v, int w) {
	adj[v].remove(w);
	adj[w].remove(v);
}

void Graph::printAdj() {
	for (auto i : V) {
		std::cout << i << ": \t";
		for (auto it : adj[i])
			std::cout << it << " ";
		std::cout << "\n";
	}
	std::cout << "\n---------------\n";
}

