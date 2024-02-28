class Solution {
public:
   int dp1[102];
   int dp[102];
   int solve1(vector<int>&nums,int ind){
        if(ind>=nums.size())return 0;
        if(dp1[ind]!=-1)return dp1[ind];
        int inc=nums[ind]+solve1(nums,ind+2);
        int exc=solve1(nums,ind+1);

        return dp1[ind]=max(inc,exc);
    }
    int solve2(vector<int>&nums,int ind){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int inc=nums[ind]+solve2(nums,ind+2);
        int exc=solve2(nums,ind+1);

        return dp[ind]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>a1,a2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)a1.push_back(nums[i]);
            if(i!=nums.size()-1) a2.push_back(nums[i]);
        }
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        int ans1=solve1(a1,0);
        int ans2=solve2(a2,0);

        return max(ans1,ans2);
    }
};