class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int j=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>k){
                while(j<=i&&mp[nums[i]]>k){
                    mp[nums[j]]--;
                    j++;
                }
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};