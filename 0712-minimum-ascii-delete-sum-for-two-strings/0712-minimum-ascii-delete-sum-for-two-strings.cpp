class Solution {
public:
    int solve(int i, int j , string &s , string & t,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int cost = 0;
        if(i==s.size() || j == t.size()){
            for(;i<s.size();i++)cost+=s[i];
            for(;j<t.size();j++)cost+=t[j];
            return cost;
        }

        if(s[i]==t[j]){
            cost = solve(i+1,j+1,s,t,dp);
        }
        else
        {
            int a  = s[i]+solve(i+1,j,s,t,dp);
            int b = t[j]+solve(i,j+1,s,t,dp);
            cost = min(a,b);
        }

        return dp[i][j]=cost;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+2, vector<int>(m+2, -1));

        return solve(0,0,s1,s2,dp);
    }
};