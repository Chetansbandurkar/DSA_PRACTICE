class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>>s;
        int cur_min=nums[0];

        for(int i=1;i<nums.size();i++){
            while(!s.empty() && nums[i]>=s.top().first){
                s.pop();
            }
            if(!s.empty() && s.top().second<nums[i]){
                return true;
            }

            s.push({nums[i],cur_min});
            cur_min=min(nums[i],cur_min);
        }

        return false;
    }
};