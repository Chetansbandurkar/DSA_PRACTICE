class Solution {
public:
    int n, m;

    bool solve(int i, int j, vector<vector<int>>& g, int h,
               vector<vector<int>>& vis) {

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        // Entering this cell costs g[i][j]
        h -= g[i][j];

        if (h <= 0)
            return false;

        // Already reached this cell with equal or better health
        if (h <= vis[i][j])
            return false;

        vis[i][j] = h;

        if (i == n - 1 && j == m - 1)
            return true;

        return solve(i + 1, j, g, h, vis) ||
               solve(i - 1, j, g, h, vis) ||
               solve(i, j + 1, g, h, vis) ||
               solve(i, j - 1, g, h, vis);
    }

    bool findSafeWalk(vector<vector<int>>& g, int h) {
        n = g.size();
        m = g[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        return solve(0, 0, g, h, vis);
    }
};