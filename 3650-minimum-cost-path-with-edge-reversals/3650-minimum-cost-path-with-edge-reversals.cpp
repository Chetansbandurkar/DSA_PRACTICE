struct temp {
    int v;
    int w;
    bool present;
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<temp>> g(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            g[u].push_back({v, w, true});
            g[v].push_back({u, w, false});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int>dist(n+1, INT_MAX);
        dist[0]=0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto node = pq.top();
            int u = node.second;
            int w = node.first;
            pq.pop();

            if (u == n - 1)
                return w;

            if (w < dist[u])
                continue;

            for (auto it : g[u]) {
                int v = it.v;
                int wt = it.w;
                int present = it.present;

                if (present && w + wt < dist[v]) {
                    pq.push({w + wt, v});
                    dist[v] = w + wt;
                }
                if (!present && w + 2*wt < dist[v]) {
                    pq.push({w + 2 * wt, v});
                    dist[v] = w + 2 * wt;
                }
            }
        }

        return -1;
    }
};