class Solution {
public:
    bool dfs(int node, int col,vector<vector<int>>&g, vector<int>&vis){
        vis[node]=col;
        bool ans = true;
        for(auto v:g[node]){
            if(vis[v]!=-1 && vis[v]==col) return false;
            if(vis[v]!=-1) continue;
           ans &= dfs(v,!col,g,vis);
        }

        return ans;
    }
    bool isBipartite(vector<vector<int>>&g) {
        int n = g.size();
        vector<int>vis(n+1,-1);
        bool ans = true;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                ans&=dfs(i,0,g,vis);
            }
        }
        return ans;
    }
};