class Solution {
public:
using ll = long long ;
    long long minCost(int n, int m, vector<vector<int>>& penalty) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        vector<vector<vector<ll>>> d(
            n, vector<vector<ll>>(m, vector<ll>(2, LLONG_MAX)));
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>
            pq;
        pq.push({1, 0, 0, 0});
        d[0][0][0] = 1;
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            ll curCost = v[0];
            int x = v[1];
            int y = v[2];
            int p = v[3];

            if (d[x][y][p] < curCost)
                continue;

            // wait
            ll nd = curCost + penalty[x][y];
            if (nd < d[x][y][p ^ 1]) {
                d[x][y][p ^ 1] = nd;
                pq.push({nd, x, y, p ^ 1});
            }
            p^=1;

            for (int k = 0; k < 4; k++) {

                int nx = dx[k] + x;
                int ny = dy[k] + y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                bool ok = false;

                if (p == 1) {
                    // odd action
                    if ((dx[k] == 1 && dy[k] == 0) ||
                        (dx[k] == 0 && dy[k] == 1))
                        ok = true;
                } else {
                    // even action
                    if ((dx[k] == -1 && dy[k] == 0) ||
                        (dx[k] == 0 && dy[k] == -1))
                        ok = true;
                }

                ll cost = curCost + 1LL * (nx + 1) * (ny + 1);

                if (!ok)
                    cost += penalty[x][y];

                if (cost < d[nx][ny][p]) {
                    d[nx][ny][p] = cost;
                    pq.push({cost, nx, ny, p});
                }
            }
        }

        return min(d[n-1][m-1][0],d[n-1][m-1][1]);
    }
};