class Solution {
public:
    int solve(vector<int>& a, int& k, int ind,vector<int>&dp) {
        if (ind == a.size()) {
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int n = a.size();
        int max_ele = INT_MIN;
        int mx_sum = INT_MIN;
        int len = 0; // it Will goest till ind+3
        for (int i = ind; i < min(n, ind + k); i++) {
            len++;
            max_ele = max(max_ele, a[i]);
            int sum = (len * max_ele) + solve(a, k, i+ 1,dp);
            mx_sum = max(mx_sum, sum);
        }

        return dp[ind]=mx_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return solve(arr, k, 0,dp);
    }
};