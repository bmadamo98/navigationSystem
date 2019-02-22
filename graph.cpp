// library
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <iostream>
#include "graph.h"

using namespace std;

// Function to create a new adjacency list node 
struct ELEMENT* newELEMENT(int v, int w)
{
	struct ELEMENT* node = new ELEMENT[sizeof(struct ELEMENT)];
	node->v = v;
	node->w = w;
	node->next = NULL;
	return node;
}

// Function to create graph (int V # of vertices)
 Graph* makeGraph(int V)
 {
	struct Graph* graph = new Graph[sizeof(struct Graph)];
	graph->V = V;
	graph->array = new AdjList[(V * sizeof(struct AdjList)) + 1];  
	for (int i = 0; i < V + 1; ++i) {
		graph->array[i].head = NULL;
	}
	return graph;
}

// Adds an edge to the directed graph
void addEdge(struct Graph* graph, int u, int v, int w)
{
	struct ELEMENT* node = newELEMENT(v, w);
	node->next = graph->array[u].head;
	graph->array[u].head = node;
}



