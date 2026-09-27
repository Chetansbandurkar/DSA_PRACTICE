class Solution {
public:
    bool check(int i, int j, vector<int>& nums) {
        vector<int> f(501, 0);
        for (int l = i; l <= j; l++)
            f[nums[l]]++;
        for (int l = 1; l <= 500; l++) {
            if (f[l] <= 0)
                continue;
            f[l]--;
            for (int k = 1; k <= 500; k++) {
                if(f[k]<=0)continue;
                f[k]--;
                int val = l+k;
                if(val<=500 && f[val]>0) return true;
                f[k]++;
            }
            f[l]++;
        }

        return false;
    }
    int maxSubarray(vector<int>& nums) {
        int ans  = 0;
        int n = nums.size();
         ans  = min(2, n);

        int l = 0;
        int r = 2;
        while(r<n){
            if(check(l,r,nums)){
                l++;
                r++;
            }else{
                ans = max(ans, r-l+1);
                r++;
            }
        }

        return ans ;
    }
};