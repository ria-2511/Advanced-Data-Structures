// a code in C++ to implement a graph using adjacency matrix i.e. a 2D array 

#include <iostream>
using namespace std;

#define V 5 // defining the number of vertices 

void addEdge(int graph[][V], int u, int v) 
{
    graph[u][v] = 1; // that position in the matrix becomes one indicating that a value exists there 
}

int main()
{
    int graph[V][V] = {0}; // initialising a 2D array to 0

    addEdge(graph, 0, 1); // operating addEdge function to each edge 
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);

    cout << "Adjacency matrix:" << endl; // printing the final matrix 
    for (int i=0; i < V; i++) // running loop from 0 to V for a 2D Matrix 
    {
        for (int j=0; j < V; j++) // running an inner Loop in the Matrix 
            cout << graph[i][j] << "   "; // simply printing the graph as the matrix 
        cout << endl;
    }
    return 0;
}