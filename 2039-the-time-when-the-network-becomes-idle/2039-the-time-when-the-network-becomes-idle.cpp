class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> g(n);
        queue<int> q;
        for (auto it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), dist(n, INT_MAX);
        q.push(0);
        vis[0] = 1;
        dist[0] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : g[node]) {
                if (!vis[it]) {
                    dist[it] = dist[node] + 1;
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int dst = dist[i];
            dst *= 2;
            int cur = 0;
            int num = (dst - 1) / p[i];
            cur = (p[i] * num) + dst;
            ans = max(cur, ans);
        }
        return ans + 1;
    }
};