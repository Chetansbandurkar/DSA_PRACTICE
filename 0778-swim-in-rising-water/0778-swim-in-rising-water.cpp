class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
        int ans = INT_MIN;
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({g[0][0], 0, 0});
        // vis[0][0] = 1;
        ans = g[0][0];
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();

            int val = v[0];
            int x = v[1];
            int y = v[2];

            if(x==n-1 && y==m-1) return val ;

            if(vis[x][y]) continue;

            vis[x][y]=1;

            for(int i=0;i<4;i++){
                int nx = dx[i]+x;
                int ny = dy[i]+y;
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(vis[nx][ny]) continue;
                int vl = max(val , g[nx][ny]);
                pq.push({vl, nx, ny});
            }
        }

        return -1;
    }
};