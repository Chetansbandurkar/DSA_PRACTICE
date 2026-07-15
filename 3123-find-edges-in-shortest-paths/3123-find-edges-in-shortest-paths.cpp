class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, long long>>> g(n);
        for (auto it : edges) {
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> ste(n, INT_MAX), ets(n, INT_MAX);
        pq.push({0, 0});
        ste[0]=0;
        while (!pq.empty()) {
            auto node = pq.top();
            long long d = node.first;
            int u = node.second;
            pq.pop();
            if (ste[u] < d)
                continue;
            for (auto it : g[u]) {

                int v = it.first;
                long long w = it.second;

                if (ste[v] > w + d) {
                    ste[v] = w + d;
                    pq.push({ste[v],v });
                }
            }
        }
        pq.push({0, n - 1});
        ets[n-1]=0;
        while (!pq.empty()) {
            auto node = pq.top();
            long long d = node.first;
            int u = node.second;
            pq.pop();
            if (ets[u] < d)
                continue;
            for (auto it : g[u]) {

                int v = it.first;
                long long w = it.second;

                if (ets[v] > w + d) {
                    ets[v] = w + d;
                    pq.push({ets[v], v});
                }
            }
        }
        vector<bool>ans(edges.size(), false);
        long long shortest = ste[n - 1];

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2];

            if (ste[u] + w + ets[v] == shortest ||
                ste[v] + w + ets[u] == shortest) {
                ans[i] = true;
            }
        }

        return ans;

        return ans;
    }
};