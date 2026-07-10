class Solution {
public:
    bool dfs(int node , int col , vector<int>&vis, vector<vector<int>>&g){
        vis[node]=col;
        bool ans = true;
        for(auto v : g[node]){
            if(vis[v]!=-1 && vis[v]==col) return false;
            if(vis[v]!=-1)continue;
            ans &=dfs(v,!col,vis, g);
        }

        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dl) {
        vector<int> vis(n + 1, -1);
        vector<vector<int>> g(n + 1);
        for (auto it : dl) {
            int u = it[0];
            int v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool ans = true;
        for(int i=0;i<=n;i++){
            if(vis[i]==-1)
            {
                ans&=dfs(i, 0, vis,g);
            }
        }

        return ans ;
    }
};