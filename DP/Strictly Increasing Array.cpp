//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int memo(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
         if(curr>=nums.size()){
            return 0;
        }
        // if(prev!=-1)  prev +1 ke jagah store kr lo iske alava
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        // include
        int include=0;
        //   check for also you have to adjust the element in betwwen them so diff matters
        if(prev==-1|| nums[curr]>nums[prev] && nums[curr]-nums[prev]>=curr-prev){
            include=memo(nums,curr+1,curr,dp)+1;
        }
        int exclude=memo(nums,curr+1,prev,dp)+0;
        // if(prev!=-1)
        dp[curr][prev+1]=max(include,exclude);
        return max(include,exclude);
    }
    int min_operations(vector<int>& nums) {
        // Code here
        vector<vector<int>>dp(nums.size()+4,vector<int>(nums.size()+4,-1));
        return nums.size()-memo(nums,0,-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends