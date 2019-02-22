#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <iostream>
#include "utility.h"
#include <stack> 

using namespace std;

// function to print out the correct adjacency list graph
void printArr(int dist[], int n, int dest)
{
	cout << endl << "LENGTH: " << dist[dest] << endl;
}

// iterative function to get the correct order
void print_list(ELEMENT* traverse)
{
	if (traverse == NULL) return;
	print_list(traverse->next);
	cout << "(" << traverse->v << ", " << traverse->w << "); ";
}

// function to print the contents of a graph
void printGraph(struct Graph* graph) {
	int vertice = graph->V;
	for (int i = 1; i != (vertice + 1); i++) {
		cout << "\n" << i << ": ";
		ELEMENT* iterator = graph->array[i].head;     
		print_list(iterator);
	}
}


// Main dijkstra function 
void dijkstra(struct Graph* graph, int u, int dest, int flag)
{
	int V = (graph->V) + 1;            // altered this. array will have exactly one more thing then normal to account for v + 1
	int *dist = new int[V];    

	struct MinHeap* minHeap = createMinHeap(V);
	int* parent = new int[V];   // parent array
	std::stack<int> MYSTACK; // stack that tracks the contents of the parent path

	// set to all null values
	for (int i = 0; i < V; i++) {
		parent[i] = NULL;
	}
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}
	minHeap->array[u] = newMinHeapNode(u, dist[u]);
	minHeap->pos[u] = u;
	dist[u] = 0;
	decreaseKey(minHeap, u, dist[u]);

	minHeap->size = V;
	
	int temp = 0;
	while (!isEmpty(minHeap))
	{
		struct heapNode* heapNode = getMin(minHeap);
		// check temp against u.
		int u = heapNode->v; 
		if (u == dest) {
			break;
		}
		struct ELEMENT* iterator = graph->array[u].head;
		while (iterator != NULL)
		{
			int v = iterator->v;
			

			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && iterator->w + dist[u] < dist[v])
			{
				dist[v] = dist[u] + iterator->w;
				decreaseKey(minHeap, v, dist[v]);
				parent[v] = u; // parent 
			}
			// produces correct final path? 

			iterator = iterator->next;
		}
	}
	if (dist[dest] == INT_MAX) {
		cout << endl << "Sorry, node " << dest << " is not reachable from node " << u << "." << endl;
	}else { // if node value valid 
		if (flag == 0) {
			printArr(dist, V, dest);
		}else if (flag == 1) {
			cout << endl;
			int z = dest;
			MYSTACK.push(dest);
			while (z != u) {
				int p = parent[z];
				MYSTACK.push(parent[z]);
				z = p;
			}
			cout << endl;
			cout << "PATH: ";
			while (!(MYSTACK.empty())) {
				cout << MYSTACK.top() << " ";
				MYSTACK.pop();
			}
			cout << endl;
		}else{
			cout << "Error: Invalid flag value.";
		}
	}
	delete[]dist;  // delete mem
}
