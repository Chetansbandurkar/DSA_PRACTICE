class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // <sum,index>
        map<int,int>mp;
        int sm=0;
        mp[sm]=-1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // sm+=nums[i];
            if(nums[i]==1)sm+=1;
            else sm-=1;
            if(mp.find(sm)!=mp.end()){
                ans=max(ans,i-mp[sm]);
            }else{
                mp[sm]=i;
            }

        }

        return ans;
    }
};