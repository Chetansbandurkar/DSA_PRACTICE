class Solution {
public:
    long long dfs(int node, vector<vector<int>>& g, vector<int>& b) {
        if (g[node].size() == 0)
            return b[node];
        long long earliest = LLONG_MAX, latest = 0;
        for (auto it : g[node]) {
            long long ChildFinishTime = dfs(it, g, b);
            earliest = min(earliest, ChildFinishTime);
            latest = max(latest, ChildFinishTime);
        }

        long long ownDuration = (latest - earliest) + b[node];
        long long parentFinishTime = latest + ownDuration;

        return parentFinishTime;
    }
    long long finishTime(int n, vector<vector<int>>& edges,vector<int>& baseTime) {
        vector<vector<int>> g(n);
        for (auto it : edges) {
            g[it[0]].push_back(it[1]);
        }


        return dfs(0,g,baseTime);
    }
};