class Solution {
public:
    int dp[101][101][101];
    int mod = 1e9+7;
    int solve(int&n,int&m,int r,int c,int mxmove){
        if((r==n || c>=m || r<0 || c<0)){
            return 1;
        }
        if(mxmove<=0)return 0;

        if(dp[r][c][mxmove]!=-1)return dp[r][c][mxmove];
        // up
        int ans=0;
        ans=(ans+solve(n,m,r-1,c,mxmove-1))%mod;
        ans=(ans+solve(n,m,r+1,c,mxmove-1))%mod;
        ans=(ans+solve(n,m,r,c-1,mxmove-1))%mod;
        ans=(ans+solve(n,m,r,c+1,mxmove-1))%mod;

        return dp[r][c][mxmove]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        memset(dp,-1,sizeof(dp));
        return solve(m,n,startRow,startColumn,maxMove);
    }
};