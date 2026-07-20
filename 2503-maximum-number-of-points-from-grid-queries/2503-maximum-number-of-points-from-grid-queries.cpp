class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& q) {
        vector<pair<int, int>> sq;
        for (int i = 0; i < q.size(); i++) {
            sq.push_back({q[i], i});
        }
        sort(sq.begin(), sq.end());
        int points = 0;
        int n = g.size();
        int m = g[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        pq.push({g[0][0], 0, 0});
        vector<int> ans(q.size(), 0);
        vis[0][0] = 1;
        for (auto it : sq) {
            int qi = it.first;
            int ind = it.second;
            while (!pq.empty() && pq.top()[0] < qi) {
                points++;
                auto v = pq.top();
                pq.pop();
                int r = v[1];
                int c = v[2];
                for (int i = 0; i < 4; i++) {
                    int nr = dx[i] + r;
                    int nc = dy[i] + c;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        pq.push({g[nr][nc], nr, nc});
                    }
                }
            }

            ans[ind] = points;
        }

        return ans;
    }
};