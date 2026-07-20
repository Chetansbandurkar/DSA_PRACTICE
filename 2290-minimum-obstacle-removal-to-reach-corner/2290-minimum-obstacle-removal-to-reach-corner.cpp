class Solution {
    // using ll = long long;

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // min heap ?? yes ?? dijkastra ?? yes
        // you can also use queue but there is aposibility that you will end up
        // with the repettive insertion  & you will not have any control over
        // the elimination of the states -> so go with the Dijkastra ->>>>>>>>>

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        // dist, r,c

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = get<0>(it);
            int r = get<1>(it);
            int c = get<2>(it);

            if (r == n - 1 && c == m - 1)
                return d;

            if (d > dist[r][c])
                continue;

            // if(r==n-1 && c==m-1) return d;
            for (int i = 0; i < 4; i++) {
                int nx = r + dx[i];
                int ny = c + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nD = d + grid[nx][ny];
                    if (nD < dist[nx][ny]) {
                        pq.push({nD, nx, ny});
                        dist[nx][ny] = nD;
                    }
                }
            }
        }

        return -1;
    }
};