class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;

        while(i<=j){
            int md=(i+j)/2;
            if(target==nums[md]){
                return md;
            }else if(target>nums[md]){
                i=md+1;
            }
            else{
                j=md-1;
            }
        }
        return i;
    }
};