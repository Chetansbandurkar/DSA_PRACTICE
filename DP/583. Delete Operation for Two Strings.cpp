
class Solution {
public:
   int dp[503][503];
    int solve(string&s,string&t,int ind1,int ind2){
        if(ind1>=s.size() && ind2>=t.size())return 0;
        if(ind1>=s.size()){
            return t.size()-ind2;
        }
        if(ind2>=t.size()){
            return s.size()-ind1;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int d=0;
        if(s[ind1]!=t[ind2]){
            d=1+min(solve(s,t,ind1+1,ind2),solve(s,t,ind1,ind2+1));
        }
        int sim=0;
        if(s[ind1]==t[ind2]){
            sim=solve(s,t,ind1+1,ind2+1);
        }
        return dp[ind1][ind2]=max(d,sim);
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};