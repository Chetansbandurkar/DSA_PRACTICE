class Solution {
public:
   const int mod = 1e9+7;
    int solve(vector<int>&dp,int src , int end , vector<int>&dist, vector<vector<pair<int,int>>>&g){
        if(dp[src]!=-1) return dp[src];
        if(src==end) return 1;
        int ans = 0;
        for(auto it: g[src]){
            if(it.first!=src && dist[src]>dist[it.first]){
                ans = (ans+solve(dp,it.first,end,dist,g))%mod;
            }
        }

        return dp[src]=ans%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n + 1);
        for (auto it : edges) {
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, n});
        dist[n]=0;
        while (!pq.empty()) {
            auto node = pq.top();
            int u = node.second;
            int w = node.first;
            pq.pop();
            if (dist[u] < w)
                continue;
            for (auto it : g[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[v] > w + wt) {
                    pq.push({w + wt, v});
                    dist[v] = w + wt;
                }
            }
        }

        vector<int>ways(n+1, 0);
        vector<int>dp(n+1,-1);
        return solve(dp,1,n, dist, g);

    }
};