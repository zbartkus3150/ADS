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
}

void Graph::DFSRec(int v, bool* visited) {
	if (visited[v] == false)
		std::cout << v << " ";
	visited[v] = true;

	for (auto it = adj[v].begin(); it != adj[v].end(); it++)
		if (!visited[*it])
			DFSRec(*it, visited);
}

bool* Graph::bDFS(int v) {
	bool* visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++)
		visited[i] = false;
	visited[v] = true;
	std::cout << v << " ";// << " ->  ";
	DFSRec(v, visited);
	std::cout << std::endl;
	for (int i = 0; i < V.size(); i++)
		if (visited[i] == false)
			break;
	return visited;
}

void Graph::DFSRecNoPrint(int v, bool* visited) {
	visited[v] = true;
	for (auto it = adj[v].begin(); it != adj[v].end(); it++)
		if (!visited[*it])
			DFSRecNoPrint(*it, visited);
}

bool Graph::IsConnected() {
	int i;
	bool* visited = new bool[V.size()];
	for (i = 0; i < V.size(); i++)
		visited[i] = false;
	for (i = 0; i < V.size(); i++)
		if (adj[i].size() != 0)
			break;
	if (i == V.size())
		return true;
	DFSRecNoPrint(i, visited);
	for (i = 0; i < V.size(); i++)
		if (visited[i] == false && adj[i].size() > 0)
			return false;
	return true;
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
		if (queue.front() != v)
			std::cout << queue.front() << " ";
		queue.pop_front();
	}
	delete visited;
	std::cout << std::endl;
}

bool* Graph::IsBool(bool* visited, bool* d) {
	bool* b = new bool[V.size()];
	for (int i = 0; i < V.size(); i++) {
		if (visited[i] || d[i])
			b[i] = true;
		else
			b[i] = false;
	}
	return b;
}

void Graph::Components(){
	int i, j, h;
	bool* visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++) //array reset
		visited[i] = false;
	for (int j = 1; j < V.size()+1; j++) {
		for (h = 0; h < V.size(); h++) { 
			if (!visited[h]) break; // connectivity check
		}
		if (h == V.size()) {
			if (j == 2)
				std::cout << "Graph is connected" << std::endl;
			else
				std::cout << "Graph is not connected" << std::endl;
			return;
		}
		std::cout << "Component " << j << ": ";
		visited = IsBool(visited, bDFS(h));
		std::cout << std::endl;
	}
}


int Graph::isEulerian()
{
	if (IsConnected() == false)
		return 0;
	int odd = 0;
	for (int i = 0; i < V.size(); i++)
		if (adj[i].size() & 1)
			odd++;
	if (odd > 2)
		return 0;
	if (odd)
		return 1;
	else
		return 2;
}
