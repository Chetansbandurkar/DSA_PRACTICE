class Solution {
public:
    int recc(vector<int>& nums, int target, int ind) {
        if (ind == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        int plus = recc(nums, target - nums[ind], ind + 1);
        int minus = recc(nums, target + nums[ind], ind + 1);

        return plus + minus;
    }
    int memo(vector<int>& nums, int target, int ind,
             map<pair<int, int>, int>& dp) {
        if (ind == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        if (dp.find({ind, target}) != dp.end())
            return dp[{ind, target}];
        int plus = memo(nums, target - nums[ind], ind + 1, dp);
        int minus = memo(nums, target + nums[ind], ind + 1, dp);

        dp[{ind, target}] = plus + minus;

        return dp[{ind, target}];
    }
    int tab(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        //   bases case
        dp[{nums.size(), 0}] = 1;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int sum = -total; sum <= total; sum++) {
                int plus = dp.find({i + 1, sum - nums[i]}) != dp.end()
                               ? dp[{i + 1, sum - nums[i]}]
                               : 0;
                int minus = dp.find({i + 1, sum + nums[i]}) != dp.end()
                                ? dp[{i + 1, sum + nums[i]}]
                                : 0;

                dp[{i, sum}] = plus + minus;
            }
        }
        return dp[{0, target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>(1001,-1));
        //  here is cattch  as we are decressing and increasing the value
        // so we will not have an -ve index so we cant use the 2d vector
        // have to shidf to the map this is the catch

        // MEMO
        // map<pair<int,int>,int>dp;
        // return memo(nums,target,0,dp);

        // TAB
        return tab(nums, target);
    }
};