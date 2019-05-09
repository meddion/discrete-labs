#include <iostream>
#include <cstdio>
#include "Graph.h"

int main()
{
	Graph graph;
	// create nodes
	graph.addVertex('A');
	graph.addVertex('B');
	graph.addVertex('C');
	graph.addVertex('D');
	graph.addVertex('F');
	graph.addVertex('N');
	graph.addVertex('E');
	// connect nodes
	graph.connectVertex('N', 'A');
	graph.connectVertex('A', 'N');
	graph.connectVertex('A', 'B');
	graph.connectVertex('B', 'C');
	graph.connectVertex('C', 'F');
	graph.connectVertex('C', 'D');
	graph.connectVertex('F', 'E');
	graph.connectVertex('E', 'D');
	
	char name1, name2, resp;
	while (true) {
		std::cout << "Set the name of the first node: ";
		std::cin >> name1;
		std::cout << "Set the name of the second node: ";
		std::cin >> name2;

		graph.setStartVertex(name1);
		graph.setEndVertex(name2);

		graph.searchSetup();
		std::cout << "\nRecursive DFS\n";
		graph.recursiveDFS(graph.getStartVertex());

		graph.searchSetup();
		std::cout << "\n\nDFS\n";
		graph.DFS(graph.getStartVertex());

		graph.searchSetup();
		std::cout << "\n\nBFS\n";
		bool result = graph.BFS();

		std::cout << "\n\nNode " << name1 << " and node " << name2;
		if (result)
			std::cout << " are connected!";
		else
			std::cout << " aren't connected!";

		do {
			std::cout << "\n\nPress 'y' to continue (or 'n' to quit): ";
			std::cin >> resp;
		} while (resp != 'y' && resp != 'n' && resp != 'Y' && resp != 'N');

		if (resp == 'n' || resp == 'N')
			break;
	}
	return 0;
}