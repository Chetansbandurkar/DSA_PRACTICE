class Solution {
public:
    vector<long long> dijkstra(int src,
                               vector<vector<pair<int, int>>>& g,
                               int n) {

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges,
                            int src1, int src2, int dest) {

        vector<vector<pair<int, int>>> g(n), rev(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            g[u].push_back({v, w});
            rev[v].push_back({u, w});   // reverse graph
        }

        vector<long long> d1 = dijkstra(src1, g, n);
        vector<long long> d2 = dijkstra(src2, g, n);
        vector<long long> d3 = dijkstra(dest, rev, n);

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {

            if (d1[i] == LLONG_MAX ||
                d2[i] == LLONG_MAX ||
                d3[i] == LLONG_MAX)
                continue;

            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};