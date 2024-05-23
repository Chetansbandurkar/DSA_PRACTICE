class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        dp[n - 1][m - 1] = grid[n- 1][m - 1];

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1){
                    dp[i][j]=max(dp[i][j],dp[i+1][j]);
                }

                if(j<m-1){
                    dp[i][j]=max(dp[i][j],dp[i][j+1]);
                }
                dp[i][j]=max(dp[i][j],grid[i][j]);
            }
        }

        // for (int i = 0; i < n;i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j<m-1)
                ans=max(ans,dp[i][j+1]-grid[i][j]);
                if(i<n-1)
                ans=max(ans,dp[i+1][j]-grid[i][j]);
            }
        }

        return ans;
    }
};