class Solution {
public:
int dp[1005];
    int solve(string s,int ind){
        if(ind>=s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];

        vector<int>fr(26,0);
        int res=1001;
        for(int j=ind;j<s.size();j++){
            fr[s[j]-'a']++;
            int mn=INT_MAX;
            int mx=INT_MIN;
            for(int i=0;i<26;i++){
                if(fr[i]){
                    mn=min(fr[i],mn);
                    mx=max(fr[i],mx);
                }
            }
            if(mx==mn){
                res=min(res,1+solve(s,j+1));
            }
        }
        return dp[ind]=res;
    }
    int minimumSubstringsInPartition(string s) {
       memset(dp,-1,sizeof(dp));
       return solve(s,0);
    }
};