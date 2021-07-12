/* BFS implementation code 
code used from this repository - https://github.com/fit-coder/fitcoderyoutube

in BFS the elements are traversed in a Breadth first manner 
here we have a queue to check the elements being visited and a array to keep track of the visited nodes 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) // usual function to add edge and create a nested vector
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void bfs(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    /* initialising a boolean vector named 'visited' with a size same as the graph vector using the command 
    'graph->size()' and initialising all elements to zero i.e. false since its a boolean vector   */
    
    queue<int> q; // an integer queue using queue data type of STL c++
    q.push(start); // pushing the first element in the queue since the BFS starts from 0 , value passed in function
    visited[start] = true; // making the first element of visited boolean vector as true 
    
    while (!q.empty()) 
    {
        int v = q.front(); // traversing the first element of the queue 
        cout << v << "  ";
        q.pop(); // deleting the first element of the queue
        
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) 
        {
            if (!visited[*i]) 
            {
                q.push(*i);
                visited[*i] = true;
            }
        }
        
        /* Note about the above loop - 
        So it starts with i = graph[v].begin()  i.e. the first element of the nested loop of v till the last
        element of the nested loop of v. ( something like this - {{1,2,3},{0,1}} etc. ).
        It checks if the 'v' is visited , if not then it marks it as visited and puts it in the 
        visied vector otherwise continues.
        Then it comes out of the 'for' loop and goes back to the 'while' loop. Int v becomes q.front() and 
        then v is printed and then poped. This was 'while' loop keeps changing the value of 'v' and 'for' 
        loop adjusts the value of the visited vector and the queue according to the visited and not visited 
        nodes. This goes on until the queue is empty , i.e. all  nodes have been visited.
        */
        
    }
}
int main() {
    int V = 7; // number of vertices
    vector<int> graph[V]; // making a vector named Graph with size - V

    addEdge(graph, 0, 1); // adding edges to the graph vector 
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    cout << "BFS traversal starting from node 0:" << "  ";
    bfs(graph, 0); // apply BFS from vertext 0 
    return 0;
}

