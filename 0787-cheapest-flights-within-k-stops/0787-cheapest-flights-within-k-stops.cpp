class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto it : f) {
            g[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        pq.push({0,0,src});
        dist[src][0]=0;

        while (!pq.empty()) {
            auto vec = pq.top();
            int d = vec[0];
            int ck = vec[1];
            int u = vec[2];
            pq.pop();
            if (u == dst)
                return d;
            if (ck > k)
                continue;

            for (auto it : g[u]) {
                int v = it.first;
                int p = it.second;
                if (dist[v][ck + 1] > p + d) {
                    dist[v][ck + 1] = p + d;
                    pq.push({dist[v][ck + 1], ck + 1, v});
                }
            }
        }

        return -1;
    }
};