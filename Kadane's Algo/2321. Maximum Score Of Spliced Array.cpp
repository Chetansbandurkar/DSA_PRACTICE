class Solution {
public:
    int calcMaxProfit(vector<int>nums1,vector<int>nums2){
        int sm=0;
        // profit will be stored in the nums2
        int n=nums1.size();
        for(int i=0;i<n;i++){
            nums2[i]-=nums1[i];
            sm+=nums1[i];
        }

        //  aply kadanes algo rithm to find the max profit if we swap the element 
        // in the array 
        int ans=-1;
        nums2[0]=nums2[0]<0?0:nums2[0];
        ans=max(ans,nums2[0]);
        for(int i=1;i<n;i++){
            nums2[i]+=nums2[i-1];
            if(nums2[i]<0)nums2[i]=0;

            ans=max(ans,nums2[i]);
        }

        return sm+ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(calcMaxProfit(nums1,nums2),calcMaxProfit(nums2,nums1));
    }
};