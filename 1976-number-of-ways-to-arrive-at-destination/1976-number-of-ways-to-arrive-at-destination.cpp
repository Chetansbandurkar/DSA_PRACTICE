class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int >>,
                       greater<pair<long long, int >>>
            pq;
        vector<long long > dist(n, LLONG_MAX), ways(n, 1);

        vector<vector<pair<int,long long>>> g(n);
        for (auto it : roads) {
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        const int mod = 1e9 + 7;

        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            int u = node.second;
            long long time = node.first;

            pq.pop();

            if(time>dist[u]) continue;
            for (auto it : g[u]) {
                int v = it.first;
                long long tm = it.second;
                if (dist[v] > tm + time) {
                    dist[v] = tm + time;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                } else if (dist[v] == tm + time) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};