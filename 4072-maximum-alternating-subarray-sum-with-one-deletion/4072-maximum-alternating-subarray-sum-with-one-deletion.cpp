class Solution {
public:
    long long solve(int ind, int par, int del, vector<int>& nums,
                    vector<vector<vector<long long >>>& dp) {
        if (ind >= nums.size())
            return 0;

        if (dp[ind][par][del] != LLONG_MIN)
            return dp[ind][par][del];
        long long ans = 0;

        // take
        int valToBeUsed = par == 1 ? -1 * nums[ind] : nums[ind];

        long long take = valToBeUsed + solve(ind + 1, !par, del, nums, dp);
        ans = max(ans , take);
        // skip if not deleted
        if (del == 0) {
            long long skip =  solve(ind + 1, par, 1, nums, dp);
            ans = max(ans,skip);
        }

        return dp[ind][par][del] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long >>(2, vector<long long>(2, LLONG_MIN)));

        long long ans = LLONG_MIN ;
        for (int i = 0; i < n; i++) {
            long long cur =  nums[i] + solve(i + 1, 1, 0, nums, dp);
            ans = max(cur, ans);
        }

        return ans;
    }
};