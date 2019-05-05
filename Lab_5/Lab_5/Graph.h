#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

class Graph
{
private:
	struct Edge 
	{
		Edge(int id, int weight) : id(id), weight(weight) {}
		int id;
		int weight;
	};

	struct Vertex 
	{
		Vertex() {}
		Vertex(char name) : name(name) {}
		char name;
		std::vector<Edge> edges;
	};

	std::map<int, bool> visited;
	std::queue<int> queue;

	std::map<int, Vertex> vertices;
	std::map<char, int> table;
	int startVertex;
	int endVertex;
	int vertexId;

	// private functions
	auto findIterByName(char name) const;
public:
	Graph();
	~Graph();
	void addVertex(char name);
	void removeVertex(char name);
	void connectVertex(int src, int ext, int weight = 0);
	void connectVertex(char src, char ext, int weight = 0);

	// for search
	void setStartVertex(char name);
	int getStartVertex() const;
	void setEndVertex(char name);
	int getEndVertex() const;
	void searchSetup();
	bool isVisited(int id);
	void DFS(int id);
	void recursiveDFS(int id);
	bool BFS();
};

