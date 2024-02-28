class Solution {
public:
    int dp[102];
    int solve(vector<int>&nums,int ind){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int inc=nums[ind]+solve(nums,ind+2);
        int exc=solve(nums,ind+1);

        return dp[ind]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};