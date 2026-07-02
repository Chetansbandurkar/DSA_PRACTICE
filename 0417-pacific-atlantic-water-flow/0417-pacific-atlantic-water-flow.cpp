class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& h) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if (x < 0 || y < 0 || x >= vis.size() || y >= vis[0].size() ||
                vis[x][y])
                continue;
            if (h[x][y] >= h[i][j])
                dfs(x, y, vis, h);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
            dfs(0, i, a, h);
        for (int i = 0; i < n; i++)
            dfs(i, 0, a, h);

        for (int i = 0; i < m; i++)
            dfs(n - 1, i, p, h);
        for (int i = 0; i < n; i++)
            dfs(i, m - 1, p, h);

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && p[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};