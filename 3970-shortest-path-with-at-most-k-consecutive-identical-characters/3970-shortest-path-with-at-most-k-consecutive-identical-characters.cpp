class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Dijkastra ?
        // weight, count ,node
        // made a graph
        vector<vector<pair<int, int>>> g(n);
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        // {weight, charCnt, node};

        for (auto it : edges) {
            g[it[0]].push_back({it[1], it[2]});
        }

        q.push({0, {1, 0}});
        dist[0][1] = 0;
        while (!q.empty()) {
            auto node = q.top();
            int u = node.second.second;
            int cnt = node.second.first;
            int w = node.first;
           
            q.pop();
             if(dist[u][cnt]<w) continue;
            for (auto it : g[u]) {
                int v = it.first;
                int wt = it.second;
                int val = (labels[v] == labels[u]) ? (cnt + 1) : 1;
                if ( val<=k  && wt + w < dist[v][val]) {
                    dist[v][val] = wt + w;
                    q.push({dist[v][val], {val, v}});
                }
            }
        }
        long long ans = INT_MAX;
        for (int i = 1; i <= k; i++) {
            ans = min(ans, 1LL*dist[n - 1][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};