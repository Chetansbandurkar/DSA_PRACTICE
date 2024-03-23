class Solution {
public:
   int solve(int i,int j,vector<int>&v,int &k,vector<vector<int>>&dp ){
    if(abs(v[i]-v[j])<=k){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int inc=v[i]+solve(i+1,j,v,k,dp);
    int exc=v[j]-v[i]-k+solve(i,j-1,v,k,dp);

    return dp[i][j]=min(inc,exc);
   }
    int minimumDeletions(string word, int k) {
        map<char,int>mp;
        for(auto it:word){
            mp[it]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int n=v.size()-1;
        vector<vector<int>>dp(26,vector<int>(26,-1));
        return solve(0,n,v,k,dp);

    }
};