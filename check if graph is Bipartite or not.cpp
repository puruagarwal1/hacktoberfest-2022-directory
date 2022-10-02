#include <bits/stdc++.h>
using namespace std;


bool bipartiteBFS(int s, vector<int> color, vector<int> adj[])
{
    queue<int> q;
    color[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(int n, vector<int> adj[])
{
    vector<int> color(n + 1, -1);
    for(int i =1;i<n+1;i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, color, adj))
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int i, j, k, n, m;
    int e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for(int i =0;i<n;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (checkBipartite(n, adj))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}