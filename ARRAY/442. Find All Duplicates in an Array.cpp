class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int ind=abs(nums[i]);
            if(nums[ind-1]<0){
                ans.push_back(ind);
            }
           nums[ind-1]*=-1;
        }
        return ans;
    }
};