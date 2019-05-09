#include <iostream>

// Number of vertices in the graph 
const unsigned int V = 4;
// prints the constructed distance array 
void showSolution(int dist[], int n);
// finds the vertex with minimum distance value, from vertices not yet included in shortest path tree
int minDist(int dist[], bool isShortest[]); 
void dijkstra(int graph[V][V], int src);

int main()
{
	int graph[V][V] = { 
		{0, 44, 1, 0},
		{4, 0, 2, 10},
		{0, 3, 0, 7},
		{0, 5, 12, 0},
	};

	dijkstra(graph, 0);
	std::cin.get();
	return 0;
}

void showSolution(int dist[], int n)
{
	std::cout << "A Vertex => It's distance from src: \n";
	for (int i = 0; i < V; i++)
		std::cout << i << " => " << dist[i] << std::endl;
}

int minDist(int dist[], bool isShortest[])
{
	int min = INT_MAX; // Initialize min value 
	int min_index;

	for (int v = 0; v < V; v++)
		if (!isShortest[v] && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];     // dist[i] will hold the shortest distance from src to i 
	bool isShortest[V]; // sptSet[i] will be true if vertex i is included in shortest 

	// Initialize all distances as INFINITE and isShortest[] as false 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, isShortest[i] = false;

	// Distance of source vertex from itself is always 0 
	dist[src] = 0;

	// Find shortest path for all vertices 
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDist(dist, isShortest);

		// Mark the picked vertex as processed 
		isShortest[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++)
			// update path from src to v through u is smaller than current value of dist[v] 
			if (!isShortest[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	showSolution(dist, V);
}