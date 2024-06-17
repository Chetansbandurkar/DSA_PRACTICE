class Solution {
public:
    int dp[501][502][26];
    int solve(vector<int>& a, int k, int ind,  int prev) {
        if(ind==a.size()) return 0;

        int maxi=0;

        if(dp[ind][prev+1][k]!=-1) return dp[ind][prev+1][k];
        if(prev==-1){
            maxi=max(maxi,1+solve(a,k,ind+1,ind));
            maxi=max(maxi,solve(a,k,ind+1,prev));
        }else{
            if(a[ind]==a[prev]){
                maxi=max(maxi,1+solve(a,k,ind+1,ind));
            }else{
                maxi=max(maxi,solve(a,k,ind+1,prev));
                if(k>0)
                maxi=max(maxi,1+solve(a,k-1,ind+1,ind));
            }
        }

        return dp[ind][prev+1][k]=maxi;
    }
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, k, 0, -1);
    }
};