class Solution {
public:
    bool solve(int ind,string &s,int open ,vector<vector<int>>&dp){
        if(ind==s.length()){
            if(open==0) return 1;
            else return 0;
        }
        if(dp[ind][open]!=-1)return dp[ind][open];

        int check=0;

        if(s[ind]=='(' || s[ind]=='*') check|=solve(ind+1,s,open+1,dp);
        if((s[ind]==')' || s[ind]=='*') && open>0)check|=solve(ind+1,s,open-1,dp);
        if(s[ind]=='*') check|=solve(ind+1,s,open,dp);
        return dp[ind][open]=check;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,s,0,dp);
    }
};