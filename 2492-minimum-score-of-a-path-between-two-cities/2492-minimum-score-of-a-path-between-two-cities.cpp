class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        queue<int> q;
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int d = it[2];
            g[u].push_back({v, d});
            g[v].push_back({u, d});
        }
        int ans = INT_MAX;
        q.push(1);
        vector<int> vis(n + 1, 0);
        vis[1] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : g[node]) {
                ans = min(ans, it.second);
                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};