class Solution {
public:
int dp[350];
bool check(string &s,vector<string>&dict){
    for(auto i:dict){
        if(s==i) return true;
    }

    return false;
}
    bool solve(string &s,vector<string>&dict,int ind){
        if(ind==s.size()) return true;

        if(dp[ind]!=-1) return dp[ind];

        string val="";
        bool flag=false;
        for(int i=ind;i<s.size();i++){
            val+=s[i];
            if(check(val,dict)){
                flag=flag|| solve(s,dict,i+1);
            }
        }

        return dp[ind]=flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));

        return solve(s,wordDict,0);
    }
};