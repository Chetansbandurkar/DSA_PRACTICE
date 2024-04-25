class Solution {
public:
    void solve(int i, int j, int& r2, int& c2, vector<vector<int>>& land) {
        if (i >= land.size() || j >= land[0].size() || i < 0 || j < 0 ||
            land[i][j] == 0) {
            return;
        }
        r2 = max(r2, i);
        c2 = max(c2, j);
        land[i][j] = 0;
        solve(i, j + 1, r2, c2, land);
        solve(i + 1, j, r2, c2, land);
        solve(i, j - 1, r2, c2, land);
        solve(i - 1, j, r2, c2, land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = i;
                    int c2 = j;

                    solve(i, j, r2, c2, land);
                    ans.push_back({
                        r1,
                        c1,
                        r2,
                        c2,
                    });
                }
            }
        }

        return ans;
    }
};