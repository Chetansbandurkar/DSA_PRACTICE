class Solution {
public:
    int dp[1001][1001];
    int solve(string&s,string&t,int i,int j){
        if(i>=s.size() ||j>=t.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int inc=0;
        if(s[i]==t[j]){
            inc=1+solve(s,t,i+1,j+1);
        }
        int exc=max(solve(s,t,i+1,j),solve(s,t,i,j+1));

        return dp[i][j]= max(inc,exc);
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        memset(dp,-1,sizeof(dp));
        reverse(s.begin(),s.end());
        return solve(s,t,0,0);
    }
};