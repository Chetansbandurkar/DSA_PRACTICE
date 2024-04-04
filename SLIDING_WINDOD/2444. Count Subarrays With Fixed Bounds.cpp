class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long  ans=0;
        int mnIndex=-1;
        int mxIndex=-1;
        int leftBound=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                leftBound=i;
            }
            if(nums[i]==minK) mnIndex=i;

            if(nums[i]==maxK) mxIndex=i;

            int cnt=min(mnIndex,mxIndex)-leftBound;

            ans+=(cnt<=0)?0:cnt;
        }
        return ans;
    }
};