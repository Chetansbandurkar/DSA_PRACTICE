class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        int n = heightMap.size();
        int m = heightMap[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][m - 1], i, m - 1});
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (!vis[0][i])
                pq.push({heightMap[0][i], 0, i});
            if (!vis[n - 1][i])
                pq.push({heightMap[n - 1][i], n - 1, i});
            vis[0][i] = 1;
            vis[n - 1][i] = 1;
        }

        int res = 0;
        while(!pq.empty()){
            auto v = pq.top();
            int x = v[1];
            int y = v[2];
            int h = v[0];

            pq.pop();

            for(int k=0;k<4;k++)
            {
                int nx = dx[k]+x;
                int ny = dy[k]+y;
                if(nx<0 || ny < 0 || nx>=n || ny >=m) continue;
                if(vis[nx][ny]) continue;


                vis[nx][ny]=1;
                int nh = heightMap[nx][ny];
                if(nh<h) res+=h-nh;
                pq.push({max(h,nh), nx, ny});
            }
        }

        return res;
    }
};