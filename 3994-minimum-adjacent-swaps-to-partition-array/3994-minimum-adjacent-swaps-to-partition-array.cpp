class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int ans = 0;
        int mid = 0;
        int last = 0;
        int n = nums.size();
        const int mod = 1e9+7;
        for (int i = 0; i < n; i++) {

            if(nums[i]<a){
                ans=(ans +mid+last)%mod;
            }
            else if(nums[i]>=a && nums[i]<=b){
                ans=(ans+last)%mod;
                mid++;
            }
            else {
                last++;
            }
        }

        return ans ;
    }
};