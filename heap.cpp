#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <iostream>
#include "heap.h"


using namespace std;

// Function to create a new Heap Node 
heapNode* newMinHeapNode(int v, int dist)
{
	struct heapNode* minNode = new heapNode[sizeof(struct heapNode)];
	minNode->v = v;
	minNode->dist = dist;
	return minNode;
}

// Function to create a Min Heap 
MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = new MinHeap[sizeof(struct MinHeap)];
	minHeap->pos = new int[capacity * sizeof(int)];
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = new heapNode*[capacity * sizeof(struct heapNode*)];
	return minHeap;
}

// Function to swap two nodes 
void swapHeapNode(struct heapNode** x, struct heapNode** y)
{
	struct heapNode* t = *x;
	*x = *y;
	*y = t;
}

// Heapify function 
void minHeapify(struct MinHeap* minHeap, int u)
{
	int smallest, left, right;
	smallest = u;
	left = 2 * u + 1;
	right = 2 * u + 2;
	if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist){
		smallest = left;
	}
	if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist) {
		smallest = right;
	}
	if (smallest != u){
		heapNode *smallestNode = minHeap->array[smallest];
		heapNode *idxNode = minHeap->array[u];
		minHeap->pos[smallestNode->v] = u;
		minHeap->pos[idxNode->v] = smallest;
		swapHeapNode(&minHeap->array[smallest], &minHeap->array[u]);
		minHeapify(minHeap, smallest);
	}
}

// Function checks if min heap is empty
int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

// Function gets minheap
heapNode* getMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap)) {
		return NULL;
	}
	struct heapNode* root = minHeap->array[0];
	struct heapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;
	--minHeap->size;
	minHeapify(minHeap, 0);
	return root;
}

// Function dec dist value of a given heapNode v.
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	int i = minHeap->pos[v];

	minHeap->array[i]->dist = dist;

	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
	{
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

// Function checks if heapNode is in min heap
int isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size) {
		return 1;
	}
	return 0;
}
