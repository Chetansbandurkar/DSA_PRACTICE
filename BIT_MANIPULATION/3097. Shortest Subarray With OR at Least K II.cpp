class Solution {
public:
    int doOR(vector<int>&orval ,int b){
        int ans=0;
        for(int i=31;i>=0;i--){
            // check for the set bit
            if((1<<i)&b){
                orval[i]++;
            }
            if(orval[i]){
                ans|=(1<<i);
            }
        }
        return ans;
    }
    // undo bit of current if val>k
    int unDoOR(vector<int>&orval ,int b){
        int ans=0;
        for(int i=31;i>=0;i--){
            if((1<<i)&b)orval[i]--;
            if(orval[i])ans|=(1<<i);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& a, int k) {
        if(k==0)return 1;
        int left=0,right=0,n=a.size(),val=0;
        vector<int>orval(32,0);
        int ans=INT_MAX;
        while(right<n){
            val=doOR(orval,a[right]);
            while(val>=k){
                ans=min(ans,right-left+1);
                // after removing the left one value
                // value will be
                val=unDoOR(orval,a[left]);
                left++;
            }
            right++;
        }

        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};