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
		std::cout << i << " ->  ";
		for (auto it : adj[i])
			std::cout << it << " ";
		std::cout << "\n";
	}
	std::cout << "\n---------------\n";
}

void Graph::DFSRec(int v, bool* visited) {
	if(visited[v]==false)
		std::cout << v << " ";
	visited[v] = true;

	for (auto it = adj[v].begin(); it != adj[v].end(); it++)
		if (!visited[*it])
			DFSRec(*it, visited);
}

void Graph::DFS(int v) {
	bool* visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++)
		visited[i] = false;
	visited[v] = true;
	std::cout << v << " ->  ";
	DFSRec(v, visited);
	std::cout << std::endl;
	delete visited;
}

void Graph::BFS(int v) {
	bool* visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++)
		visited[i] = false;

	std::list<int> queue;
	visited[v] = true;
	queue.push_back(v);
	std::cout << queue.front() << " ->  ";

	while (!queue.empty()) {
		for (auto it = adj[queue.front()].begin(); it != adj[queue.front()].end(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
		if(queue.front() != v)
			std::cout << queue.front() << " ";
		queue.pop_front();
	}
	delete visited;
	std::cout << std::endl;
}