class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // {cost, row, col}
        cost[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int bCost = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (bCost > cost[r][c])
                continue;

            // Up
            if (r > 0) {
                int cu = bCost;
                if (g[r][c] != 4)
                    cu++;

                if (cu < cost[r - 1][c]) {
                    cost[r - 1][c] = cu;
                    pq.push({cu, r - 1, c});
                }
            }

            // Down
            if (r < n - 1) {
                int cd = bCost;
                if (g[r][c] != 3)
                    cd++;

                if (cd < cost[r + 1][c]) {
                    cost[r + 1][c] = cd;
                    pq.push({cd, r + 1, c});
                }
            }

            // Right
            if (c < m - 1) {
                int cr = bCost;
                if (g[r][c] != 1)
                    cr++;

                if (cr < cost[r][c + 1]) {
                    cost[r][c + 1] = cr;
                    pq.push({cr, r, c + 1});
                }
            }

            // Left
            if (c > 0) {
                int cl = bCost;
                if (g[r][c] != 2)
                    cl++;

                if (cl < cost[r][c - 1]) {
                    cost[r][c - 1] = cl;
                    pq.push({cl, r, c - 1});
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};