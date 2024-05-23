class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>c(31,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<31;j++){
                if(nums[i]&(1<<j)){
                    c[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<31;i++){
            if(k&(1<<i)){
                if(c[i]&1){
                    continue;
                }
                else{
                    cnt++;
                }
            }else if(c[i]%2==1){
                cnt++;
            }
        }

        return cnt;
    }
};