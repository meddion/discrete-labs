#include <iostream> 

// Number of vertices in the graph 
const unsigned int V = 5;
// For vertices not connected to each other
const unsigned int INF = 99999;

// A function to print the solution matrix 
void showSolution(int dist[V][V]);

// Floyd Warshall algorithm
void floydWarshall(int graph[V][V]);

// driver program to test above function 
int main()
{
	int graph[V][V] = { 
		{1, 4, 59, 10, 69},
		{86, 0, 6, INF, 76},
		{INF, 5, 0, 1, INF},
		{42, 11, INF, 0, 2},
		{2, 11, 1, 0, 7}
	};

	// Print the solution 
	floydWarshall(graph);

	std::cin.get();
	return 0;
}

void showSolution(int dist[V][V])
{
	std::cout << "Result: \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				std::cout << "\tINF";
			else
				std::cout << "\t" << dist[i][j];
		}
		std::cout << std::endl;
	}
}

void floydWarshall(int graph[V][V])
{
	// dist[][] will be the output matrix that will finally have the shortest
	int dist[V][V], i, j, k;

	// Initialize the solution matrix same as input graph matrix
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the 
			// above picked source 
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Show the shortest distance matrix 
	showSolution(dist);
}