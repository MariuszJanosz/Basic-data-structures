#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graph.h"

void GraphInitialize(Graph* graph, size_t size)
{
	if (size == 0) exit(1);
	graph->size = size;
	graph->vertices_data = (int*)malloc(size * sizeof(int));
	graph->vertices = (char*)calloc(size, sizeof(char));
	graph->edges = (char*)calloc(size * size, sizeof(char));
	if (!graph->edges || !graph->vertices || !graph->vertices_data) exit(1);
}

void GraphInsertVertex(Graph* graph, size_t index, int data)
{
	if (index >= graph->size) exit(1);
	graph->vertices[index] = 1;
	graph->vertices_data[index] = data;
}

void GraphInsertEdge(Graph* graph, size_t index1, size_t index2)
{
	if (index1 >= graph->size || index2 >= graph->size) exit(1);
	graph->edges[index2 * graph->size + index1] = 1;
	graph->edges[index1 * graph->size + index2] = 1;
}

int GraphDeleteVertex(Graph* graph, size_t index)
{
	if (index >= graph->size) exit(1);
	if (graph->vertices[index] == 0) exit(1);
	graph->vertices[index] = 0;
	for (size_t i = 0; i < graph->size; ++i)
	{
		graph->edges[index * graph->size + i] = 0;
		graph->edges[i * graph->size + index] = 0;
	}
	return graph->vertices_data[index];
}

void GraphDeleteEdge(Graph* graph, size_t index1, size_t index2)
{
	if (index1 >= graph->size || index2 >= graph->size) exit(1);
	if (graph->edges[index2 * graph->size + index1] == 0) exit(1);
	graph->edges[index2 * graph->size + index1] = 0;
	graph->edges[index1 * graph->size + index2] = 0;
}

void GraphEmpty(Graph* graph)
{
	memset(graph->vertices, 0, graph->size);
	memset(graph->edges, 0, graph->size*graph->size);
}

void GraphDestroy(Graph* graph)
{
	free(graph->edges);
	free(graph->vertices);
	free(graph->vertices_data);
}

void GraphPrint(Graph* graph)
{
	for (size_t i = 0; i < graph->size; ++i)
	{
		if (graph->vertices[i])
		{
			printf("Vertex index %llu is present in the graph and its value is %d.\n", i, graph->vertices_data[i]);
			printf("It is connected to the following vertices:\n");
			for (size_t j = 0; j < graph->size; ++j)
			{
				if (graph->edges[i * graph->size + j]) printf("%llu ", j);
			}
			printf("\n");
		}
		else
		{
			printf("Vertex index %llu is not present in the graph.\n", i);
		}
	}
}
