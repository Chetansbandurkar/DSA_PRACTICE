class Solution {
public:
    int findSm(vector<int>&nums,int divisor){
        int ans=0;
        for(auto it:nums){
            ans+=((it+divisor-1)/divisor);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;

            int ans_=findSm(nums,mid);

            if(ans_<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};