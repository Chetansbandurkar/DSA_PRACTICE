class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sm=0;
        map<int,int>mp;
        mp[sm]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            int val=(sm%k);
            // when we mod the valu which we
            // mod value == which we have to substract or add
            // henace 7n-4=7n-4+7-7 (7==k)
            // SOLVE IT WE WILL HVE TO ADD IT
            // CASE:-> [2,-6,3,1,2,8,2,1]  ,K=7;
            if(val<0)val+=k;
            if(mp.find(val)!=mp.end()){
                ans+=mp[val];
            }
            mp[val]++;
        }

        return ans;
    }
};