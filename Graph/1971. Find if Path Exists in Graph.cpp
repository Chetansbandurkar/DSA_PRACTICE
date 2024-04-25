class Solution {
public:
bool dfs(vector<int>adj[],int node,vector<bool>&vis,int&destination){
    vis[node]=1;
    int ans=false;
    if(node==destination) ans=true;
    for(auto it:adj[node]){
        if(!vis[it]){
          ans|=dfs(adj,it,vis,destination);
        }
    }
    // if(node==destination) return true;/
    return ans;

}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // DFS
        vector<bool>vis(n,false);
        if(dfs(adj,source,vis,destination)){
            return true;
        }
        return false;
        // BFS ->
        // queue<int>q;
        // q.push(source);
        // vector<bool>vis(n,false);
        // vis[source]=1;
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     if(node==destination) return true;
        //     for(auto it:adj[node]){
        //         if(!vis[it]){
        //             q.push(it);
        //             vis[it]=1;
        //         }
        //     }
        // }

        // return false;
    }
};