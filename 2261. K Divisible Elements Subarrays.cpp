class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int cnt=0;
        // at least bola he to 0 element vala bhi chalega bhai 
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++){
            int kc=0;
            vector<int>t;
            for(int j=i;j<n;j++){

                if(nums[j]%p==0){
                    kc++;
                }
                // if(kc>0)cnt++;
                if(kc>k)break;
                t.push_back(nums[j]);
                ans.insert(t);
            }
        }

        return ans.size();
    }
};