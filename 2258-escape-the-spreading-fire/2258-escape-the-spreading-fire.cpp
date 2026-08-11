class Solution {
public:
    int maximumMinutes(vector<vector<int>>& g) {
        queue<vector<int>> q;
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    q.push({i, j, 0});
                    vis[i][j] = 0;
                } else if (g[i][j] == 2) {
                    vis[i][j] = -1;
                }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                int x = it[0];
                int y = it[1];
                int val = it[2];

                for (int k = 0; k < 4; k++) {
                    int nx = dx[k] + x;
                    int ny = dy[k] + y;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    if (vis[nx][ny] != INT_MAX)
                        continue;

                    vis[nx][ny] = val + 1;
                    q.push({nx, ny, val + 1});
                }
            }
        }

        int l = 0, h = 1e9;
        int ans = -1;

        while (l <= h) {
            int md = (l + h) >> 1;

            queue<vector<int>> q;
            bool canReach = false;
            q.push({0, 0, md});
            vector<vector<int>> v(n, vector<int>(m, 0));
            while (!q.empty()) {
                auto it = q.front();
                int x = it[0];
                int y = it[1];
                int val = it[2];
                q.pop();
                if (v[x][y])
                    continue;

                if (x == n - 1 && y == m - 1) {
                    canReach = true;
                    break;
                }

                v[x][y] = 1;

                for (int k = 0; k < 4; k++) {
                    int nx = dx[k] + x;
                    int ny = dy[k] + y;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    if (vis[nx][ny] == -1 || vis[nx][ny] == 0)
                        continue;

                    if (vis[nx][ny] > val + 1 || (nx == n - 1 && ny == m - 1 &&
                                                  vis[nx][ny] >= val + 1)) {
                        q.push({nx, ny, val + 1});
                    }
                }
            }

            if (canReach) {
                l = md + 1;
                ans = md;
            } else {
                h = md - 1;
            }
        }

        return ans;
    }
};