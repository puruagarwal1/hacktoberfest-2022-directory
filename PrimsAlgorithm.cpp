#include<bits/stdc++.h>
using namespace std;
void PrimsAlgorithm(int v,vector<pair<int,int> > adj[])
{
    vector<int>parent(v); 
    vector<int> key(v,1e9); 
    vector<bool>mst(v,false);
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int current = pq.top().second; 
        pq.pop(); 
        
        mst[current] = true; 
        
        for (auto &child : adj[current]) {
            int v = child.first;
            int weight = child.second;
            if (mst[v] == false && weight < key[v]) {
                parent[v] = current;
	            key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < v; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    
}
int main(){
	int v=5;
	vector<pair<int,int>> adj[v]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
    adj[4].push_back({2,7});
    PrimsAlgorithm(v,adj);
    
}