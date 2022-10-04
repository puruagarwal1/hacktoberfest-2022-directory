/* Author : G Pala Venki Reddy */

/* we will see algorithm to find euler path in a graph by using dfs with help of problem statement given below */

/* 
    Euler Path In Graphs :  Euler Path is a path in a graph that visits every edge exactly once
    Euler Circuit In Graphs : Euler Circuit is an Euler Path that starts and ends on the same vertex
*/    

/* Problem Statement : 
     
    A game has n levels and m teleportes between them. You win the game if you move from level 1 to level n using every teleporter exactly once.

    Can you win the game, and what is a possible way to do it?

*/

/* Input : 

    The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,…,n.

    Then, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

    You can assume that each pair (a,b) in the input is distinct.

*/

/* Output :
    Print m+1 integers: the sequence in which you visit the levels during the game. You can print any valid solution.

    If there are no solutions, print "IMPOSSIBLE".

*/

/* constraints :

    2 ≤ n ≤ 10^5
    1 ≤ m ≤ 2⋅10^5
    1 ≤ a, b ≤ n

*/

/* Example Testcase :
     
    Input:
    5 6
    1 2
    1 3
    2 4
    2 5
    3 1
    4 2

    Output:
    1 3 1 2 4 2 5

*/


#include <bits/stdc++.h>
 
using namespace std;
 
set<int> adj[100005];
 
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<int> in(n+1, 0);
    vector<int> out(n+1, 0);
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        in[v]++;
        out[u]++;
    }
 
    /* check if Eulerian path from node 1 to node n is possible */
    /* case1 : if all the nodes have same indegree and outdegree , then path exists and we can start from node1 and end at node n */
    /* case2: node 1 having outdegree = indegree + 1 and node n having outdegree = indegree -1 and all other nodes having equal indegree and outdegree or viceversa */
 
    bool isValid = true;
    int v1 = -1;
    int v2 = -1;
    for(int i = 1; i <= n; i++)
    {
        if(out[i] == in[i] + 1 && v1 == -1)
        {
            v1 = i;
        }
        else if(out[i] == in[i] -1 && v2 == -1)
        {
            v2 = i;
        }
        else if(out[i] != in[i])
        {
            isValid = false;
            break;
        }
    }
 
    if(isValid == false || v1 != 1 || v2 != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        /* now find euler path using dfs starting from node 1 */
        stack<int> s;
        s.push(1);
        vector<int> path;
        while(!s.empty())
        {
            int curr = s.top();
            if(adj[curr].empty() == true)
            {
                /* curr node is processed , add the node to path */
                path.push_back(curr);
                s.pop();
            }
            else
            {
                /* pick unvisited node adjacent to it */
                int temp = *adj[curr].begin();
                /* remove the present visited node */
                adj[curr].erase(temp);
                s.push(temp);
            }
        }
 
        /* now print the Euler  path */
        /* check no of nodes visited is equal to no of edges plus one */
        if((int)path.size() == m + 1)
        {
            reverse(path.begin(), path.end());
            if(path.front() != 1 || path.back() != n)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else
            {
                for(auto x: path)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}