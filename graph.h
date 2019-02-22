#ifndef graph_H
#define graph_H

// STRUCTS 

// A struct that represents an adjacency node
struct ELEMENT
{
	int v;
	int w;
	struct ELEMENT* next;
};

// A Struct that represents each ELEMENT node in the array of ELEMENT nodes (graph)
struct AdjList
{
	struct ELEMENT *head;  
};

// A Struct that represents the array of AdjList's, or, The Graph. 
struct Graph
{
	int V;
	struct AdjList* array;
};

// Functions

Graph* makeGraph(int V);
void addEdge(struct Graph* graph, int u, int dest, int w);
ELEMENT* newELEMENT(int dest, int w);

#endif