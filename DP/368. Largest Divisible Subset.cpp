class Solution {
public:
    // use dp of LIS bt the condition is change we have to check for the nums[j]%nums[i]
    // .also have to chek for the dp[prec]+1 >dp[prev]
    // then we can change the hash index 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int mx=1;
        int lastindex=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                lastindex=i;
            }
        }
        vector<int>tmp;
        tmp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            tmp.push_back(nums[lastindex]);
        }
        return tmp;
    }
};