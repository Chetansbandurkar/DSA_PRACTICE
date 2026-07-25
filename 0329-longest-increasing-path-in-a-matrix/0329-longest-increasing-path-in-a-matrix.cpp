class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        queue<pair<int,int>>q;
        int dx []={0,1,-1,0};
        int dy []={1,0,0,-1};
        vector<vector<int>>ind(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){

                    int nx = dx[k]+i;
                    int ny = dy[k]+j;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]>g[i][j]){
                        ind[nx][ny]++;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(ind[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int level = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--)
            {
                auto it = q.front();
                int i = it.first;
                int j = it.second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nx = dx[k]+i;
                    int ny = dy[k]+j;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]>g[i][j]){
                        ind[nx][ny]--;
                        if(ind[nx][ny]==0)q.push({nx,ny});
                    }
                }

            }

            level ++;
        }

        return level;
    }
};