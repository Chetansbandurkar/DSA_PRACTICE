class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& sp,
                          int s, int e) {
        priority_queue<pair<double, int>> pq;
        vector<vector<pair<int, double>>> g(n);

        for (int i = 0; i < ed.size(); i++) {
            int u = ed[i][0];
            int v = ed[i][1];
            g[u].push_back({v, sp[i]});
            g[v].push_back({u, sp[i]});
        }

        vector<double> dist(n, 0.0);

        pq.push({1.0, s});
        dist[s] = 1.0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            double pr = it.first;
            int u = it.second;

            if (pr < dist[u])
                continue;

            for (auto i : g[u]) {
                int v = i.first;
                double pp = i.second;
                if (dist[v] < pr * pp) {
                    dist[v] = pr * pp;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[e];
    }
};