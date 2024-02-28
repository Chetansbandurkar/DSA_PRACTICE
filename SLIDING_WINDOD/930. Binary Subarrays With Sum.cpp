class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        int sum=0;
        mp[sum]=1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int cur=sum-goal;
            if(mp.find(cur)!=mp.end()){
                ans+=mp[cur];
            }
            mp[sum]++;
        }

        return ans;
    }
};