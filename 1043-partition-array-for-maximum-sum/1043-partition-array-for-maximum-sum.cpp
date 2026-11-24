class Solution {
public:
    int solve(int ind, int& k, vector<int>& v, vector<int>& dp) {
        if (ind >= v.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int mx_sm = INT_MIN;
        int mx_val = INT_MIN;
        int len = 0;
        for (int i = ind; i < min((int)v.size(), ind + k); i++) {
            len++;
            mx_val = max(mx_val, v[i]);
            int sm = len * mx_val + solve(i + 1, k, v, dp);
            mx_sm = max(sm, mx_sm);
        }

        return dp[ind] = mx_sm;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);

        int ans = solve(0, k, arr, dp);
        return ans;
    }
};