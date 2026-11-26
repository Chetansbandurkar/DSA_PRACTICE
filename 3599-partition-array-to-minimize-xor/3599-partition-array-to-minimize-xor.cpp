class Solution {
public:
    vector<int> xr;
    int check(int ind, int k, vector<vector<int>>& dp, vector<int>& ar) {

        if (ind >= ar.size())
            return 0;
        int curXr = 0;
        if (k == 1) {
            for (int i = ind; i < ar.size(); i++) {
                curXr = curXr ^ ar[i];
            }
            return curXr;
        }

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int ans = INT_MAX;

        for (int i = ind; i <= ar.size() - k; i++) {
            curXr ^= ar[i];
            int nxtXr = check(i + 1, k - 1, dp, ar);
            ans = min(ans, max(curXr, nxtXr));
        }

        return dp[ind][k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        vector<vector<int>> dp(252, vector<int>(252, -1));
        return check(0, k, dp, nums);
    }
};
// 0 1 2 3 4 5 0 1 2 3 4