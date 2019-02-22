#ifndef heap_H
#define heap_H

// STRUCTS

// Struct to represent a min heap node 
struct heapNode
{
	int  v;
	int dist;
};

// Structure to represent a min heap 
struct MinHeap
{
	int size;      // Number of heap nodes present currently 
	int capacity;  // Capacity of min heap 
	int *pos;     // This is needed for decreaseKey() 
	struct heapNode **array;
};



// CLASSES
heapNode* newMinHeapNode(int v, int dist);
MinHeap* createMinHeap(int capacity);
void swapHeapNode(struct heapNode** a, struct heapNode** b);
void minHeapify(struct MinHeap* minHeap, int u);
int isEmpty(struct MinHeap* minHeap);
heapNode* getMin(struct MinHeap* minHeap);
void decreaseKey(struct MinHeap* minHeap, int v, int dist);
int isInMinHeap(struct MinHeap *minHeap, int v);

#endif
