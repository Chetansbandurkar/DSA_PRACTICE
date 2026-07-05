class Solution {
public:  
    int mod = 1e9+7;
    long long solve(int i, int j ,int k , string & s, string & p, string & t, vector<vector<vector<int>>>&dp)
    {
        if(k>=t.size()) return (i!=0 && j!=0);// why ??
        if(dp[i][j][k]!=-1) return dp[i][j][k];


        long long ans = 0;
        for(int i1=i;i1<s.size();i1++){
            if(s[i1]==t[k])ans = (ans+solve(i1+1,j,k+1,s,p,t,dp))%mod;
        }

        for(int i1=j;i1<p.size();i1++){
            if(p[i1]==t[k])ans = (ans+solve(i,i1+1,k+1,s,p,t,dp))%mod;
        }

        return dp[i][j][k]=ans%mod;
    }
    int interleaveCharacters(string s, string p, string t) {

        vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(101,-1)));


        return solve(0,0,0,s,p,t,dp);
        
    }
};