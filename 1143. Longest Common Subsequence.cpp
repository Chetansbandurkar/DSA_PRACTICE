class Solution {
public:
    // int dp[1001][1001];
    // int solve(string&a,string&b,int i,int j){
    //     if(i>=a.size() || j>=b.size()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans=0;
    //     // int ans2=0;
    //     if(a[i]==b[j]){
    //         ans=1+solve(a,b,i+1,j+1);
    //     }
    //     else{
    //         ans=max(solve(a,b,i+1,j),solve(a,b,i,j+1));
    //     }

    //     return dp[i][j]=ans;
    // }
    int tab(string a,string b){
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                if(a[i]==b[j]){
                    dp[i][j]=1+(dp[i+1][j+1]);
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp,-1,sizeof(dp));
        // return solve(text1,text2,0,0);
        return tab(text1,text2);

    }
};