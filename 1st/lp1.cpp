// iostream header file is used for input and output
// Example: cout, cin
#include <iostream>

// vector header file is used for dynamic arrays
#include <vector>

// queue header file is used because BFS uses Queue data structure
#include <queue>

// standard namespace
// So we can directly write cout instead of std::cout
using namespace std;


// Creating Graph class
class Graph
{
    // Variable to store total number of vertices(nodes)
    int V;

    /*
        vector<vector<int>> adj

        This is called Adjacency List.

        It is a 2D vector.

        Example:

        adj[0] -> stores neighbors of node 0
        adj[1] -> stores neighbors of node 1
        adj[2] -> stores neighbors of node 2

        Example Graph:

              0
             / \
            1   2
           / \
          3   4

        Adjacency List becomes:

        adj[0] = {1,2}
        adj[1] = {0,3,4}
        adj[2] = {0}
        adj[3] = {1}
        adj[4] = {1}

    */
    vector<vector<int>> adj;

public:

    // Constructor of Graph class
    // Automatically called when object is created
    Graph(int V)
    {
        // this->V means class variable V
        // = V means parameter value

        // Store number of vertices
        this->V = V;

        /*
            Resize adjacency list

            If V = 5

            adj[0]
            adj[1]
            adj[2]
            adj[3]
            adj[4]

            5 empty vectors are created
        */
        adj.resize(V);
    }


    // Function to add edge between two nodes
    void addEdge(int u, int v)
    {
        /*
            Add v into neighbor list of u

            Example:
            addEdge(0,1)

            adj[0] = {1}
        */
        adj[u].push_back(v);

        /*
            Add u into neighbor list of v

            Because graph is undirected

            So:

            0 connected to 1
            1 connected to 0
        */
        adj[v].push_back(u);
    }



    // BFS Function
    // Breadth First Search
    void BFS(int startNode)
    {
        /*
            Create visited array

            Purpose:
            To avoid visiting same node again

            Initially all are false

            Example:
            false false false false false
        */
        vector<bool> visited(V, false);


        /*
            Queue used in BFS

            Queue works on FIFO

            FIFO = First In First Out
        */
        queue<int> q;


        /*
            Mark starting node as visited

            Example:
            startNode = 0

            visited[0] = true
        */
        visited[startNode] = true;


        /*
            Insert start node into queue

            Queue:
            [0]
        */
        q.push(startNode);


        cout << "BFS Traversal: ";


        /*
            Loop runs until queue becomes empty
        */
        while (!q.empty())
        {
            /*
                Get front element from queue

                Example:
                Queue = [0,1,2]

                curr = 0
            */
            int curr = q.front();


            /*
                Remove front element

                Queue becomes:
                [1,2]
            */
            q.pop();


            // Print current node
            cout << curr << " ";


            /*
                Traverse all neighbors of current node

                Example:
                adj[0] = {1,2}

                neighbor becomes:
                1 then 2
            */
            for (int neighbor : adj[curr])
            {
                /*
                    If neighbor is not visited
                */
                if (!visited[neighbor])
                {
                    /*
                        Mark neighbor as visited
                    */
                    visited[neighbor] = true;


                    /*
                        Insert neighbor into queue
                    */
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }




    /*
        DFS Utility Function

        Recursive function

        curr = current node
        visited = visited array
    */
    void DFSUtil(int curr, vector<bool> &visited)
    {
        /*
            Mark current node visited
        */
        visited[curr] = true;


        /*
            Print current node
        */
        cout << curr << " ";


        /*
            Traverse all neighbors
        */
        for (int neighbor : adj[curr])
        {
            /*
                If neighbor not visited
            */
            if (!visited[neighbor])
            {
                /*
                    Recursive function call

                    DFS goes deep first

                    Example:
                    0 -> 1 -> 3
                */
                DFSUtil(neighbor, visited);
            }
        }
    }




    // DFS Function
    // Depth First Search
    void DFS(int startNode)
    {
        /*
            Create visited array

            Initially all false
        */
        vector<bool> visited(V, false);


        cout << "DFS Traversal: ";


        /*
            Call recursive DFS function
        */
        DFSUtil(startNode, visited);


        cout << endl;
    }
};




// Main function
// Program execution starts from here
int main()
{
    /*
        Create graph object

        Graph with 5 vertices

        Nodes:
        0 1 2 3 4
    */
    Graph g(5);



    /*
        Add edges between nodes
    */

    g.addEdge(0, 1);

    /*
        Graph:
        0 --- 1
    */


    g.addEdge(0, 2);

    /*
            0
           / \
          1   2
    */


    g.addEdge(1, 3);

    /*
              0
             / \
            1   2
           /
          3
    */


    g.addEdge(1, 4);

    /*
                  0
                 / \
                1   2
               / \
              3   4
    */



    cout << "Starting from node 0:\n";



    /*
        BFS Traversal

        Starts from node 0

        Output:
        0 1 2 3 4

        BFS visits level by level
    */
    g.BFS(0);




    /*
        DFS Traversal

        Starts from node 0

        Output:
        0 1 3 4 2

        DFS goes deep first
    */
    g.DFS(0);



    // Program ends
    return 0;
}