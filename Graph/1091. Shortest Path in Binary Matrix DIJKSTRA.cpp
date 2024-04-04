class Solution {
public:
    // you can use the dijkstra using PQ(min heap) just have to store the
    // min dist and update it ,,mean dist
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // DIJKSTRA
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},{1, 1},  {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        dist[0][0]=1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int dst=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(auto it:dir){
                int nr=r+it.first;
                int nc=c+it.second;
                if(nr>=0 && nr<n && nc>=0 &&nc<n && grid[nr][nc]==0){
                    if(dst+1<dist[nr][nc]){
                        dist[nr][nc]=dst+1;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }

        if(dist[n-1][n-1]!=1e9)return dist[n-1][n-1];

        return -1;

        
    }
};
// BFS
// vector<pair<int, int>> dir = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},
//                                       {1, 1},  {-1, -1}, {1, -1}, {-1, 1}};
//         int n = grid.size();
//         //    apne ko sirf 0 vale cell pe hi travel krna he
//         if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
//             return -1;
//         queue<pair<int, int>> q;
//         //  use grid as the visited array also so u should not have to visit
//         // the cell again
//         grid[0][0] = 1;
//         int steps = 0;
//         q.push({0, 0});
//         while (!q.empty()) {
//             int sz = q.size();
//             steps++;
//             while (sz--) {
//                 int row = q.front().first;
//                 int col = q.front().second;
//                 q.pop();
//                 if (row == n - 1 && col == n - 1)
//                     return steps;
//                 for (auto it : dir) {
//                     int nrow = row + it.first;
//                     int ncol = col + it.second;
//                     if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
//                         grid[nrow][ncol] == 0) {
//                         grid[nrow][ncol] = 1;
//                         q.push({nrow, ncol});
//                     }
//                 }
//             }
//         }

//         return -1;