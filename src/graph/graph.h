#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

typedef struct Graph
{
	size_t size;
	int* vertices_data;
	char* vertices;
	char* edges;
}Graph;

void GraphInitialize(Graph* graph, size_t size);

void GraphInsertVertex(Graph* graph, size_t index, int data);
void GraphInsertEdge(Graph* graph, size_t index1, size_t index2);

int GraphDeleteVertex(Graph* graph, size_t index);
void GraphDeleteEdge(Graph* graph, size_t index1, size_t index2);
void GraphEmpty(Graph* graph);

void GraphDestroy(Graph* graph);

void GraphPrint(Graph* graph);

#endif
