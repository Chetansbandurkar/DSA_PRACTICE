class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges,
                                              vector<int>& requiredSignals) {
        vector<long long> ans(n, -1);
        priority_queue<vector<long long >, vector<vector<long long>>, greater<vector<long long>>>
            pq;

        vector<vector<pair<int, int>>> g(n);
        for (auto it : edges) {
            g[it[0]].push_back({it[1], it[2]}); // node , delay
        }

        ans[0] = 0;
        for (auto it : g[0]) {
            pq.push({it.second, it.first}); // delay , node
        }

        while (!pq.empty()) {
            auto vec = pq.top();
            long long del = vec[0];
            int node = vec[1];
            requiredSignals[node]--;
            pq.pop();
            if (requiredSignals[node] != 0 or node == 0)
                continue;

            ans[node] = del;
            for (auto it : g[node]) {
                pq.push({it.second + del, it.first}); // delay , node
            }
        }

        return ans;
    }
};