#include <stdio.h>
#include <stdlib.h>

// Define the number of vertices (computers) in the graph
#define V 8

// The graph is represented by an adjacency matrix
int graph[V][V];

// Function prototypes
void initializeGraph();
void addEdge(int u, int v, int weight);
void removeEdge(int u, int v);
void printMatrix();
void DFS_util(int v, int visited[]);
void DFS(int startNode);

// Initializes the graph with no connections (all values set to 0)
void initializeGraph()
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      graph[i][j] = 0;
    }
  }
}

// Adds a connection (an edge) between two computers
void addEdge(int u, int v, int weight)
{
  // Check if the vertices are valid
  if (u >= 0 && u < V && v >= 0 && v < V)
  {
    // For an undirected graph, the connection is two-way
    graph[u][v] = weight;
    graph[v][u] = weight;
    printf("\nConnection between computers %d and %d with cost %d has been added.\n", u, v, weight);
  }
  else
  {
    printf("Error: Invalid vertex! Use values between 0 and %d.\n", V - 1);
  }
}

// Removes the connection between two computers
void removeEdge(int u, int v)
{
  if (u >= 0 && u < V && v >= 0 && v < V)
  {
    // Check if a connection actually exists
    if (graph[u][v] == 0)
    {
      printf("No connection to remove between %d and %d.\n", u, v);
    }
    else
    {
      graph[u][v] = 0;
      graph[v][u] = 0;
      printf("Connection between computers %d and %d has been removed.\n", u, v);
    }
  }
  else
  {
    printf("Error: Invalid vertex!\n");
  }
}

// Prints the adjacency matrix of the network
void printMatrix()
{
  printf("\n--- Network Adjacency Matrix (Costs) ---\n");
  printf("       ");
  for (int i = 0; i < V; i++)
  {
    printf("[%d]  ", i);
  }
  printf("\n---------------------------------------------\n");

  for (int i = 0; i < V; i++)
  {
    printf("[%d] | ", i);
    for (int j = 0; j < V; j++)
    {
      printf(" %-3d ", graph[i][j]);
    }
    printf("\n");
  }
  printf("---------------------------------------------\n");
}

// A utility function used by DFS to perform the recursive traversal
void DFS_util(int v, int visited[])
{
  // Mark the current node as visited and print it
  visited[v] = 1;
  printf("%d -> ", v);

  // Recur for all adjacent vertices that have not been visited
  for (int i = 0; i < V; i++)
  {
    if (graph[v][i] != 0 && !visited[i])
    {
      DFS_util(i, visited);
    }
  }
}

// Performs Depth-First Search traversal starting from a given node
void DFS(int startNode)
{
  if (startNode < 0 || startNode >= V)
  {
    printf("Error: Invalid starting vertex!\n");
    return;
  }

  // Array to keep track of visited nodes, initialized to 0 (false)
  int visited[V] = {0};

  printf("\nDepth-First Search (DFS) path starting from computer %d:\n", startNode);
  DFS_util(startNode, visited);
  printf("END\n");
}

int main()
{
  int option, u, v, weight, start_node_dfs;

  initializeGraph();

  // Pre-populate the graph with some initial connections
  addEdge(0, 1, 5);
  addEdge(0, 2, 10);
  addEdge(1, 3, 8);
  addEdge(2, 4, 15);
  addEdge(2, 5, 4);
  addEdge(3, 4, 7);
  addEdge(4, 6, 9);
  addEdge(5, 7, 12);
  addEdge(6, 7, 3);

  printf("\n*** Computer Network Management System ***\n");

  do
  {
    printf("\n--- OPTIONS MENU ---\n\n");
    printf("1. Add Connection (Edge)\n");
    printf("2. Remove Connection (Edge)\n");
    printf("3. View Network Matrix\n");
    printf("4. Trace Connectivity (Depth-First Search)\n");
    printf("0. Exit\n");
    printf("\nChoose an option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter the source computer (0 to %d): ", V - 1);
      scanf("%d", &u);
      printf("Enter the destination computer (0 to %d): ", V - 1);
      scanf("%d", &v);
      printf("Enter the connection cost: ");
      scanf("%d", &weight);
      addEdge(u, v, weight);
      break;
    case 2:
      printf("Enter the source computer (0 to %d): ", V - 1);
      scanf("%d", &u);
      printf("Enter the destination computer (0 to %d): ", V - 1);
      scanf("%d", &v);
      removeEdge(u, v);
      break;
    case 3:
      printMatrix();
      break;
    case 4:
      printf("Enter the starting computer for the search (0 to %d): ", V - 1);
      scanf("%d", &start_node_dfs);
      DFS(start_node_dfs);
      break;
    case 0:
      printf("\nExiting the program. Goodbye!\n");
      break;
    default:
      printf("\nInvalid option! Please try again.\n");
    }
  } while (option != 0);

  return 0;
}