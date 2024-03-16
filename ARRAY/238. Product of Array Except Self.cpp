class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        int frmb=1;
        int frme=1;
        for(int i=0;i<n;i++){
            res[i]*=frmb;
            frmb*=nums[i];
            res[n-i-1]*=frme;
            frme*=nums[n-1-i];
        }

        return res;
    }
};