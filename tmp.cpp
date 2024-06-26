class Solution
{
    using ll = long long;

public:
    long long solve(vector<int> &nums, bool flg, int ind, vector<vector<long long>> &dp)
    {
        if (ind >= nums.size())
        {
            return 0;
        }
        if (dp[ind][flg] != -1)
            return dp[ind][flg];
        long long inc = 0, exc = 0;
        long long encc = 0;
        if (flg)
        {
            inc = nums[ind] * (-1) + solve(nums, 0, ind + 1);
            exc = nums[ind] + solve(nums, flg, ind + 1)
        }
        else
        {
            encc = nums[ind] + solve(nums, 1, ind + 1);
        }

        return dp[ind][flg] = max({inc, encc, exc});
    }
    long long maximumTotalCost(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(nums, 0, 0, dp);
    }
};