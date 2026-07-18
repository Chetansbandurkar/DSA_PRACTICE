class Solution {
public:
    // Hint : staying static is not allowed you have to keep moving
    int minimumTime(vector<vector<int>>& g) {
        if(g[0][1]>1 && g[1][0]>1)  return -1;
        int n = g.size();
        int m = g[0].size();
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        // time, r, c
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        pq.push({g[0][0], 0, 0});
        time[0][0] = 0;
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int tm = v[0];
            int r = v[1];
            int c = v[2];

            if (tm > time[r][c])
                continue;

            if (r == n - 1 && c == m - 1)
                return tm;

            for (int i = 0; i < 4; i++) {
                int nr = dx[i] + r;
                int nc = dy[i] + c;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                int wait = 0;
                if (g[nr][nc] > tm)
                    wait = (g[nr][nc] - tm) % 2 == 0 ? 1 : 0;

                int mxT = max(wait+g[nr][nc], tm+1);
                if (time[nr][nc] > mxT) {
                    pq.push({mxT, nr, nc});
                    time[nr][nc] = mxT;
                }
            }
        }

        return -1;
    }
};