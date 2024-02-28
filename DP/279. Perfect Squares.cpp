class Solution {
public:
    int dp[100005];
    int solve(int n) {
        if (n == 0)
            return 1;

        if(dp[n]!=-1)return dp[n];
        int i = 1;
        int ans=INT_MAX;
        int val = i * i;
        while(i <= sqrt(n)) {
            val=i*i;
            i++;
            int calsqr=1+solve(n-val);
            ans=min(ans,calsqr);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n)-1;
    }
};