class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        int n = g.size();
        int m = g[0].size();

        vector<vector<vector<int>>> vis(
            n, vector<vector<int>>(m, vector<int>(k+1, 0)));
        queue<vector<int>> q;
        vis[0][0][0] = 1;
        q.push({0, 0, 0, 0}); // {dist,k,x,y}
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            int d = v[0];
            int ck = v[1];
            int i = v[2];
            int j = v[3];

            if (i == n - 1 && j == m - 1)
                return d;

            for (int it = 0; it < 4; it++) {
                int x = dx[it] + i;
                int y = dy[it] + j;
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                
                if(g[x][y]==1 && ck<k && !vis[x][y][ck+1]){
                    vis[x][y][ck+1]=1;
                    q.push({d+1,ck+1,x,y});
                }
                else if(g[x][y]==0 && !vis[x][y][ck]){
                    q.push({d+1,ck,x,y});
                    vis[x][y][ck]=1;
                }
            }
        }

        return -1;
    }
};