#include <iostream>

/*
    vector library

    Used for dynamic arrays

    Example:
    vector<int> arr;
*/

#include <vector>


/*
    queue library

    Used for priority_queue

    A* algorithm uses priority queue
*/

#include <queue>


/*
    algorithm library

    Used for swap()
*/

#include <algorithm>


/*
    set library

    Not used directly here
*/

#include <set>


/*
    unordered_set library

    Used to store visited states

    Fast searching
*/

#include <unordered_set>



/*
    Use standard namespace

    Avoid writing std::
*/

using namespace std;



/*
    Define puzzle size

    N = 3

    Means:
    3 x 3 puzzle
*/

#define N 3




/*
    Goal State

    Final target arrangement

    0 represents blank space

    Goal:

    1 2 3
    4 5 6
    7 8 0
*/

vector<vector<int>> goal =
{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};




/*
    Node structure

    Represents one puzzle state
*/

struct Node
{


    /*
        mat stores puzzle matrix

        Example:

        1 2 3
        4 0 5
        6 7 8
    */

    vector<vector<int>> mat;



    /*
        x and y store blank tile position

        Example:

        0 at row=1 col=1

        x=1
        y=1
    */

    int x, y;



    /*
        g = cost from start node

        Number of moves taken
    */

    int g;



    /*
        h = heuristic value

        Estimated distance to goal
    */

    int h;



    /*
        parent pointer

        Stores previous node

        Used for printing solution path
    */

    Node *parent;
};





/*
    HEURISTIC FUNCTION

    Calculates Manhattan Distance
*/

int calculateH(vector<vector<int>> &mat)
{


    /*
        h stores heuristic value
    */

    int h = 0;



    /*
        Traverse all rows
    */

    for (int i = 0; i < N; i++)
    {


        /*
            Traverse all columns
        */

        for (int j = 0; j < N; j++)
        {


            /*
                Ignore blank tile

                0 means blank space
            */

            if (mat[i][j] != 0)
            {


                /*
                    Current value - 1

                    Example:

                    value=5

                    val=4
                */

                int val = mat[i][j] - 1;



                /*
                    Goal row

                    Formula:

                    val / N
                */

                int gx = val / N;



                /*
                    Goal column

                    Formula:

                    val % N
                */

                int gy = val % N;



                /*
                    Manhattan Distance Formula

                    |x1-x2| + |y1-y2|

                    abs() gives positive value
                */

                h += abs(i - gx) + abs(j - gy);
            }
        }
    }



    /*
        Return heuristic value
    */

    return h;
}





/*
    Comparator structure

    Used for priority queue sorting
*/

struct cmp
{


    /*
        operator()

        Custom comparison function
    */

    bool operator()(Node *a, Node *b)
    {


        /*
            f(n)=g(n)+h(n)

            Smaller cost gets higher priority
        */

        return (a->g + a->h) > (b->g + b->h);
    }
};





/*
    Function to print puzzle matrix
*/

void printMatrix(vector<vector<int>> mat)
{


    /*
        Traverse every row
    */

    for (auto row : mat)
    {


        /*
            Traverse every element
        */

        for (int x : row)
        {


            /*
                Print element
            */

            cout << x << " ";
        }


        /*
            New line after row
        */

        cout << "\n";
    }



    /*
        Separator line
    */

    cout << "--------\n";
}





/*
    Function to print complete solution path
*/

void printPath(Node *node)
{


    /*
        Base condition

        If node becomes NULL
    */

    if (node == NULL)
        return;



    /*
        Recursive call

        Go to parent node first
    */

    printPath(node->parent);



    /*
        Print current matrix
    */

    printMatrix(node->mat);
}





/*
    Convert matrix into string

    Used for visited checking
*/

string toString(vector<vector<int>> &mat)
{


    /*
        Empty string
    */

    string s = "";



    /*
        Traverse rows
    */

    for (auto r : mat)
    {


        /*
            Traverse elements
        */

        for (int x : r)
        {


            /*
                Convert integer into character

                Example:

                1 -> '1'
            */

            s += char(x + '0');
        }
    }



    /*
        Return generated string
    */

    return s;
}





/*
    MAIN A* SOLVER FUNCTION
*/

void solve(vector<vector<int>> start, int x, int y)
{


    /*
        Priority Queue

        Stores nodes based on minimum cost
    */

    priority_queue<Node *, vector<Node *>, cmp> pq;



    /*
        Stores visited states
    */

    unordered_set<string> visited;





    /*
        Create root node
    */

    Node *root = new Node
    {
        start,                  // starting matrix
        x,                      // blank row
        y,                      // blank column
        0,                      // g cost
        calculateH(start),      // heuristic
        NULL                    // no parent
    };



    /*
        Insert root into queue
    */

    pq.push(root);





    /*
        Movement arrays

        Down
        Up
        Right
        Left
    */

    int dx[] = {1, -1, 0, 0};

    int dy[] = {0, 0, 1, -1};





    /*
        Loop until queue becomes empty
    */

    while (!pq.empty())
    {


        /*
            Get minimum cost node
        */

        Node *cur = pq.top();



        /*
            Remove top node
        */

        pq.pop();





        /*
            Convert matrix into string
        */

        string key = toString(cur->mat);





        /*
            If already visited

            Skip node
        */

        if (visited.count(key))
            continue;





        /*
            Mark visited
        */

        visited.insert(key);





        /*
            Goal condition

            If heuristic becomes 0
        */

        if (cur->h == 0)
        {


            /*
                Solution found
            */

            cout << "Solution Found!\n\n";



            /*
                Print complete path
            */

            printPath(cur);



            return;
        }





        /*
            Try all 4 directions
        */

        for (int k = 0; k < 4; k++)
        {


            /*
                New row position
            */

            int nx = cur->x + dx[k];



            /*
                New column position
            */

            int ny = cur->y + dy[k];





            /*
                Boundary checking

                Ensure valid position
            */

            if (nx >= 0 && ny >= 0 &&
                nx < N && ny < N)
            {


                /*
                    Copy current matrix
                */

                vector<vector<int>> newMat = cur->mat;





                /*
                    Swap blank tile

                    Move 0
                */

                swap(
                    newMat[cur->x][cur->y],
                    newMat[nx][ny]
                );





                /*
                    Convert into string
                */

                string newKey = toString(newMat);





                /*
                    If not visited
                */

                if (!visited.count(newKey))
                {


                    /*
                        Create child node
                    */

                    Node *child = new Node
                    {
                        newMat,
                        nx,
                        ny,
                        cur->g + 1,
                        calculateH(newMat),
                        cur
                    };



                    /*
                        Insert child into queue
                    */

                    pq.push(child);
                }
            }
        }
    }





    /*
        If solution impossible
    */

    cout << "No Solution Exists\n";
}





/*
    MAIN FUNCTION
*/

int main()
{


    /*
        Starting puzzle state
    */

    vector<vector<int>> start =
    {
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}
    };



    /*
        Blank tile position

        row=1
        col=1
    */

    int x = 1, y = 1;





    /*
        Call solver function
    */

    solve(start, x, y);





    /*
        Program success
    */

    return 0;
}