class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)nums[i]=1;
            else nums[i]=0;
        }
        map<int,int>mp;
        mp[0]=1;
        int sm=0;
        for(auto it:nums){
            sm+=it;
            int cur=sm-k;
            if(mp.find(cur)!=mp.end()){
                cnt+=mp[sm-k];
            }
            mp[sm]++;
        }

        return cnt;
    }
};