class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
    }
};
// BFS
vector<pair<int, int>> dir = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},
                                      {1, 1},  {-1, -1}, {1, -1}, {-1, 1}};
        int n = grid.size();
        //    apne ko sirf 0 vale cell pe hi travel krna he
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, int>> q;
        //  use grid as the visited array also so u should not have to visit
        // the cell again
        grid[0][0] = 1;
        int steps = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if (row == n - 1 && col == n - 1)
                    return steps;
                for (auto it : dir) {
                    int nrow = row + it.first;
                    int ncol = col + it.second;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == 0) {
                        grid[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return -1;