// Adjacency List representation in C++

#include <bits/stdc++.h>
using namespace std;

// here we are using Vectors as an Dynamic Array to add the elements 
// Function to Add edge
void addEdge(vector<int> adj[], int s, int d) // s and d are the vertices from which the edge is to be added 
{
  adj[s].push_back(d); // add the edge s->d in he vector in the form of an elemtent d at position s.
  adj[d].push_back(s); // add the edge d->s in he vector in the form of an elemtent s at position d.
  
  //inserts them something like this - {{1,2,3},{0,2},{0,1},{0},{}}

}

// Print the graph
void printGraph(vector<int> adj[], int V) 
{
  for (int d = 0; d < V; ++d) 
  {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x; 
      
      /* IMPORANT NOTE ABOUT THE ABOVE LOOP 
      So the Loop we ran to add the egdes . inserted them like this - {{1,2,3},{0,2},{0,1},{0},{}}
      So now this loop to print them all , and what "auto x" actually does is , it loops each and every 
      sublist in the above 2D Vector . So for d=0 i.e. iteration number 1 , it gives 1,2,3 as its output 
      and so on! This was all the edges and the graph is printed. 
      */
      
    printf("\n");
  }
}

int main() {
  int V = 5; // for the number of edges 

  // Create a graph
  vector<int> adj[V]; // defining a vector with size 5 i.e. no of edges 

  // Add edges
  addEdge(adj, 0, 1); // adding edges one by one 
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V); // printing all the edges of the graph 
}
