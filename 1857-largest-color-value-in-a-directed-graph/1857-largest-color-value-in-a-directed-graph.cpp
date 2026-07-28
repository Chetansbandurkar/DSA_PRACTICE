class Solution {
public:
    int dfs(int node, vector<vector<int>>& g, vector<int> &vis,
            vector<vector<int>>& col, string& clrs) {
        if (!vis[node]) {
            vis[node] = 1;
            for (auto next : g[node]) {
                if (dfs(next, g, vis, col, clrs) == INT_MAX)
                    return INT_MAX;
                for (int c = 0; c < 26; c++) {
                    col[node][c] = max(col[node][c], col[next][c]);
                }
            }
            col[node][clrs[node] - 'a']++;
            vis[node] = 2;
        }

        return vis[node] == 2 ? col[node][clrs[node] - 'a'] : INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<vector<int>> col(n, vector<int>(26, 0));
        for (auto it : edges) {
            g[it[0]].push_back(it[1]);
        }

        int ans = 0;
        vector<int> vis(n);

        for (int i = 0; i < n && ans != INT_MAX; i++) {
            // vector<int>vis(n);
            ans = max(ans, dfs(i, g, vis, col, colors));
        }

        return ans==INT_MAX?-1:ans;
    }
};