#include "Graph.h"

Graph::Graph():vertexId(0)
{
}

Graph::~Graph()
{
}

/* Finding methods */
auto Graph::findIterByName(char name) const
{
	for (auto i = vertices.begin(); i != vertices.end(); i++)
		if (i->second.name == name)
			return i;

	throw std::exception("Iterator wasn't find.");
}

/* Adding a vertex */
void Graph::addVertex(char name)
{
	this->vertices.insert(std::pair<int, Vertex>(this->vertexId, Vertex(name)));
	this->table.insert(std::pair<char, int>(name, this->vertexId));
	this->vertexId++;
}

/* Removing a vertex and it's tail */
void Graph::removeVertex(char name)
{
	// finds a position of a vertex that we're look for
	auto mapIter = this->findIterByName(name);
	int srcId = mapIter->first;

	// before it removes a vertex from a map, it needs to look up for edges with other vertices
	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
		if (i == mapIter) 
			continue;

		std::vector<Edge>* edges = &i->second.edges;

		bool resized;
		do {
			resized = false;
			for (auto j = edges->begin(); j != edges->end(); j++) {
				if (j->id == srcId) {
					edges->erase(j);
					resized = true;
					break;
				}
			}
		} while (resized);
	}
	// finally deletes a vertex from a map
	this->vertices.erase(mapIter);
	this->table.erase(this->table.find(name));
}

/* Connection of vertices */
void Graph::connectVertex(int src, int ext, int weight)
{
	// creates an edge & binds an edge to a vertex
	this->vertices[src].edges.push_back(Edge(ext, weight));
}

void Graph::connectVertex(char src, char ext, int weight)
{
	// finds a key (id) by a name (value)
	int srcId = this->findIterByName(src)->first; // assigns a key value 
	int extId = this->findIterByName(ext)->first;
	// creates an edge & binds an edge to a vertex
	this->connectVertex(srcId, extId, weight);
}

/* Searching algorithms and helpers methods*/
// setter
void Graph::setStartVertex(char name)
{
	this->startVertex = this->table[name];
}
// getter
int Graph::getStartVertex() const
{
	return this->startVertex;
}
// setter
void Graph::setEndVertex(char name)
{
	this->endVertex = this->table[name];
}

int Graph::getEndVertex() const
{
	return this->endVertex;
}

void Graph::searchSetup()
{
	float mode = this->visited.empty();

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
		if (mode)
			this->visited.insert(std::pair<int, bool>(i->first, false));
		else
			this->visited[i->first] = false;
	}
}

bool Graph::isVisited(int id)
{
	return this->visited[id];
}

// breadth-first search
bool Graph::BFS()
{
	while (!this->queue.empty()) this->queue.pop();

	this->queue.push(this->startVertex);
	this->visited[this->startVertex] = true;

	while (!queue.empty()) {
		Vertex vertex = this->vertices[queue.front()];
		queue.pop();

		std::cout << vertex.name << " ";

		if (this->table[vertex.name] == this->endVertex)
			return true;

		for (auto edge : vertex.edges) {
			if (!this->visited[edge.id]) {
				queue.push(edge.id);
				this->visited[edge.id] = true;
			}
		}
	}
	return false;
}

void Graph::DFS(int id)
{
	std::vector<int> stack;
	stack.push_back(id);

	while (!stack.empty()) {
		int id = stack.back();
		stack.pop_back();
		if (!this->visited[id]) {
			this->visited[id] = true;
			Vertex& vertex = this->vertices[id];

			std::cout << vertex.name << " ";

			for (auto edge : vertex.edges)
				stack.push_back(edge.id);
		}

	}
}

void Graph::recursiveDFS(int id)
{
	visited[id] = true;
	Vertex& vertex = this->vertices[id];

	std::cout << vertex.name << " ";

	for (auto edge : vertex.edges)
		if (!visited[edge.id]) 
			recursiveDFS(edge.id);
}