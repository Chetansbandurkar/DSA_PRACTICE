class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j]=true;
                }
                else if(i+1==j){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
            }
        }

        int ans=0;
        for(auto it:dp){
            for(auto x:it){
                ans+=x;
            }
        }
        return ans;
    }
};