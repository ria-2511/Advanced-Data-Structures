/* DFS implementation code 
code used from this repository - https://github.com/fit-coder/fitcoderyoutube

This algorithm makes the visited nodes while ignoring the cycles. 
Here we maintain a Stack to keep track of the visited and non visited nodes. We keep on adding the adjacent 
neighbours to the stack and then letting them out through the TOP like it happens in a regular stack 
and then marking them as visited in the visited boolean vector. 
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) // regular function to add edges and nodes 
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void dfs_iterative(vector<int> graph[], int start) // for iterative DFS 
{
    vector<bool> visited(graph->size(), false); // creating a bool visited vector with size same as the graph vector and initalize all of it to False 
    stack<int> st; // initalize stack <int>
    st.push(start); // push the first value in the stack 
    visited[start] = true; // mark the first value of vector as visited
    while (!st.empty()) 
    {
        int v = st.top();
        cout << v << "  ";
        st.pop();
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) 
        {
            if (!visited[*i]) 
            {
                st.push(*i);
                visited[*i] = true;
            }
        }
        // the loops are same as the regular BFS code. See note in that code to understand.
    }
}

void dfs_recursive(vector<int> graph[], vector<bool>& visited, int node) // recursive approach to DFS
{
    visited[node] = true; // node -> starting point , therefore initalize first vector element to node 
    cout << node << "  ";
    for (auto i = graph[node].begin(); i != graph[node].end(); i++)  
    {
        if (!visited[*i]) 
           dfs_recursive(graph, visited, *i); // recursive function with the starting node values being changed 
    }
    
    /* here also the outer part of the 'for' loop is used to change the values of 'node' and then the 
    'for loop is used to iterate one by one to the nested loop elements i.e. each adjacent node of the 'node'
    selected. 'if(!visited)' means that if the 'visited'!=0 then the 'if' loop will be executed and it will 
    call the main function again and again for each and every value of 'i' */
}

int main() {
    int V = 7; // number of vertices
    vector<int> graph[V]; // defining a vector of the name graph with a size of V 

    addEdge(graph, 0, 1); // adding adges using the regular algorithm 
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    cout << "DFS traversal iterative starting from node 0:" << "  ";
    dfs_iterative(graph, 0); // applying DFS using the iterative approach 
    cout << endl;

    cout << "DFS traversal recursive starting from node 0:" << "  ";
    vector<bool> visited(graph->size(), false); // create a visited vector with graph size same and all values as false 
    dfs_recursive(graph, visited, 0); // applying DFS using the recursive approach 

    return 0;
}