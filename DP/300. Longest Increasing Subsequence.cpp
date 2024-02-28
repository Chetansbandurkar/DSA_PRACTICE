class Solution {
public:
    // inlude exclude pattern 
    int Recc(vector<int>&nums,int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }

        // include
        int include=0;
        if(prev==-1|| nums[curr]>nums[prev]){
            include=Recc(nums,curr+1,curr)+1;
        }
        int exclude=Recc(nums,curr+1,prev)+0;

        int ans=max(include,exclude);

        return ans;
    }
    int memo(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
         if(curr>=nums.size()){
            return 0;
        }
        // if(prev!=-1)  prev +1 ke jagah store kr lo iske alava
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        // include
        int include=0;
        if(prev==-1|| nums[curr]>nums[prev]){
            include=memo(nums,curr+1,curr,dp)+1;
        }
        int exclude=memo(nums,curr+1,prev,dp)+0;
        // if(prev!=-1)
        dp[curr][prev+1]=max(include,exclude);

        return max(include,exclude);

    }
  
    int tab(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+4,vector<int>(n+4,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1|| nums[curr]>nums[prev]){
                include=dp[curr+1][curr+1]+1;
                }
                int exclude=dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }

        return dp[0][0];
        
    }
    int SO(vector<int>&nums){
        int n=nums.size();
        vector<int>c(n+2,0);
        vector<int>p(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1|| nums[curr]>nums[prev]){
                include=p[curr+1]+1;
                }
                int exclude=p[prev+1];

                c[prev+1]=max(include,exclude);
            }
            p=c;
        }
        return p[0];

    }
    int optimize(vector<int>&nums){
        // by using binary search

        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int solvetb(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]
                }
            }
        }

    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return Recc(nums,curr,prev);
        // return memo(nums,curr,prev,dp);
        // return tab(nums);
        // return SO(nums);
        return optimize(nums); 
    }
};