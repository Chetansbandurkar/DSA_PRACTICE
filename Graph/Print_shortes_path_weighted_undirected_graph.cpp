#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // create the adj list for undirected graph
        // as we have to store the weight create the vec.pair list for i
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // create the min heap to store the dist of node peiority wise
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // create the dist array to store the dist 
        // also create the parent map to store we rech at that node i.e index from which node 
        // i.e value at tha index
        // map parent with self 
        vector<int>dist(n+1,1e9),parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dist[1]=0;
        // as the src node is 0 it dit will be alway 0 as 0->0=0 (1)
        pq.push({0,1});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;// it will act as a parent to store it in the parent vec
            int dis=it.first;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgW=it.second;
                if(edgW+dis<dist[adjNode]){
                    dist[adjNode]=edgW+dis;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        // matlab destination tak nahi pohach paye return -1
        if(parent[n]==1e9)
        {
            return {-1};
        }
        vector<int>path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

int main()
{
    // Driver Code

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {

        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}