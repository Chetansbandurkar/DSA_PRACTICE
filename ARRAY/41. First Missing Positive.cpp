class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=nums.size()+1;
        int n=nums.size();
        bool contains1=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                contains1=true;
            }
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }

        if(!contains1)return 1;

        for(int i=0;i<nums.size();i++){
            int val=abs(nums[i]);
            int ind=val-1;
            if(nums[ind]<0)continue;
            nums[ind]*=-1;
        }
        // the index at which the calu is pos it will be missing
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                return i+1;
            }
        }

        return ans;
    }
};