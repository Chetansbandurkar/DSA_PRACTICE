class Solution {
public:
int dp[101][101];
int solve(int k_ind,int r_ind,unordered_map<char,vector<int>>&mp,string 
&ring ,string&key){
    if(k_ind==key.size()) return 0;

    if(dp[k_ind][r_ind]!=-1)  return dp[k_ind][r_ind];
    int ans=1e6;
    char ch=key[k_ind];
    for(auto j:mp[ch]){
        // both cases for anticlockwise & clockwise
        ans=min(ans,
        1+min(abs(r_ind-j),(int)(ring.size()-abs(r_ind-j)))+solve(k_ind+1,j,mp,ring,key)
        );
    }

    return dp[k_ind][r_ind]=ans;
}
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<ring.size();i++){
            mp[ring[i]].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,mp,ring,key);
    }
};