class Solution {
public:
    int ans = 0;
    int n;
    int m;
    bool dfs(int& days, int i, int j, vector<vector<int>>& vis,
             vector<vector<int>>& g) {
        if (i < 0 || i >= n || j >= m || j < 0 || vis[i][j] || g[i][j] <= days)
            return false;

        vis[i][j] = 1;

        if (i == n - 1)
            return 1;

        return dfs(days, i + 1, j, vis, g) || dfs(days, i - 1, j, vis, g) ||
               dfs(days, i, j - 1, vis, g) || dfs(days, i, j + 1, vis, g);
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        vector<vector<int>> cel(row, vector<int>(col, 0));
        int i = 1;
        n = row;
        m = col;

        for (auto it : cells) {
            int x = it[0];
            int y = it[1];
            x--, y--;
            cel[x][y] = i;
            i++;
        }

        int l = 0;
        int h = row * col;
        int ans = 0;

        while (l <= h) {
            int md = l + (h - l) / 2;

            bool val = false;
            vector<vector<int>> vis(row, vector<int>(col, 0));
            for (int i = 0; i < col; i++) {
                if (dfs(md, 0, i, vis, cel)) {
                    val = true;
                    break;
                }
            }

            if (val) {
                ans = md;
                l = md + 1; // search later days
            } else {
                h = md - 1;
            }
        }

        return ans;
    }
};