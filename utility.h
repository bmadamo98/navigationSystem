#ifndef utility_H
#define utility_H
#include "graph.h"
#include "heap.h"


struct ListNode {
	int *list;
	int vertice = 0;
	ListNode* next;
};

struct List {
	int i = 0;
	ListNode* head;
};

// functions
void print_list(ELEMENT* traverse);
void printArr(int dist[], int n, int dest);
void printGraph(struct Graph* graph);
void dijkstra(struct Graph* graph, int u, int dest, int flag);

#endif
