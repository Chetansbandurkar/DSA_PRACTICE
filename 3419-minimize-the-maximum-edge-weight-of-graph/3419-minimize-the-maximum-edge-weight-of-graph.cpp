class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mn = 0;
        vector<vector<pair<int, int>>> g(n);
        for (auto it : edges) {
            g[it[1]].push_back({it[2], it[0]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> vis(n, 0);

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int u = node.second;
            int w = node.first;
            if (vis[u])
                continue;
            vis[u] = 1;

            mn = max(w, mn);

            for (auto it : g[u]) {
                if (!vis[it.second]) {
                    pq.push(it);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return -1;
        }

        return mn;
    }
};