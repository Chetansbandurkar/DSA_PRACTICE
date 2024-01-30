class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int cnt=0;
        int ans=0;
        while(j<nums.size()){
            cnt+=(nums[j]==0);
            while(cnt>k && i<=j){
                cnt-=(nums[i]==0);
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }

        return ans;
    }
};