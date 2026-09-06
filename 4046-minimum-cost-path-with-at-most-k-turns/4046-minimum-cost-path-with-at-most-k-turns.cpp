class Solution {
public:
    int minCost(vector<vector<int>>& g, int k) {
        int n = g.size();
        int m = g[0].size();
        // R , D , L , U
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        // val , k , last dir , i, j ??
        vector<vector<vector<vector<int>>>> cost(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(5, vector<int>(k + 1, INT_MAX))));

        pq.push({g[0][0], 0, 0, 0, 0});
        cost[0][0][0][0] = g[0][0];

        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int val = v[0];
            int dst = v[1];
            int lastD = v[2];
            int x = v[3];
            int y = v[4];

            if (cost[x][y][lastD][dst] < val)
                continue;

            for (int j = 0; j < 4; j++) {
                int nx = dx[j] + x;
                int ny = dy[j] + y;
                int nDst = dst;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (lastD != 0 && lastD != j + 1)
                    nDst++;
                if (nDst > k)
                    continue;
                int nCost = val + g[nx][ny];
                if (cost[nx][ny][j + 1][nDst] <= nCost)
                    continue;
                cost[nx][ny][j + 1][nDst] = nCost;
                pq.push({nCost, nDst, j + 1, nx, ny});
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= k; j++) {
                ans = min(ans, cost[n - 1][m - 1][i][j]);
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};