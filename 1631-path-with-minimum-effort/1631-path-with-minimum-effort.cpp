class Solution {
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int n, m;

public:
    void dfs(int x, int y, int& limit, vector<vector<int>>& g,
             vector<vector<int>>& vis) {

        if (vis[x][y])
            return;
        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {

            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            int newLimit = abs(g[nx][ny] - g[x][y]);
            if (newLimit <= limit) {
                dfs(nx, ny, limit, g, vis);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& ht) {

        n = ht.size();
        m = ht[0].size();

        int ans = 0;
        int l = 0;
        int h = 1e6;

        while (l <= h) {
            int md = (l + h) >> 1;

            vector<vector<int>> vis(n, vector<int>(m, 0));
            dfs(0, 0, md, ht, vis);
            if (vis[n - 1][m - 1]) {
                ans = md;
                h = md - 1;
            } else {
                l = md + 1;
            }
        }

        return ans;
    }
};