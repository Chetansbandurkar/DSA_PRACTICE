class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int> path, int& k, int n,
               int ind) {
        if (n < 0 || path.size() > k)
            return;
        if (n == 0 && path.size() == k && ind - 1 <= 9) {
            ans.push_back(path);
            return;
        }
        if(ind>9)return ;
        path.push_back(ind);
        solve(ans, path, k, n - ind, ind + 1);
        path.pop_back();
        solve(ans, path, k, n, ind + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(ans, path, k, n, 1);
        return ans;
    }
};