#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode* head;
};
struct Graph
{
	int V;
	struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest, int weight) {
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;

}
struct Graph* createGraph(int V) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct AdjList*)malloc(V * sizeof(struct ))

}