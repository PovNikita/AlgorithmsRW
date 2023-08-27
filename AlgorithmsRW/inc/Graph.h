#pragma once
#include <iostream>
#include <time.h>
#include "Stack.h"
#include "Queue.h"


void CreateMatrix(bool*** Matrix, int column, int row);		//This function creates adjacency matrix
void ShowMatrix(bool** Matrix, int column, int row);		//This function shows adjacency matrix
void CreateLinksInMatrix(bool*** Matrix, int column, int row, int* x, int* y, int n_pairs);	//This function create links between nodes of the graph
void CreateRandomLinksInMatrix(bool*** Matrix, int nodes);	//This function create random links between nodes of the graph
void DFS(bool** Matrix, bool** visited, int node, int nodes, stack_static* stack);		//This function makes depth-first search with recursion
bool* StackDFS(bool** Matrix, int node, int nodes, stack_static* stack);				//This function makes depth-first search without recursion
bool* NoDuplicatesStackDFS(bool** Matrix, int node, int nodes, stack_static* stack);	//This function makes depth-first search without recursion and without duplication in the stack
bool* BFS(bool** Matrix, int node, int nodes, stack_static* stack);		//This function makes breadth-first search
bool IsGraphBipartite(bool** Matrix, int node, int nodes);				//This based on DFS function will returns 'true', if the graph is bipartite. Otherwise, it returns 'false'