class Solution {
public:
    int solve(int ind, int diff, vector<int>& r, vector<vector<int>>& dp) {
        if (ind >= r.size()) {
            return diff == 0 ? 0 : -1e9;
        }

        if(dp[ind][diff]!=-1) return dp[ind][diff];

        // don't include 
        int ans = solve(ind+1, diff, r, dp);

        // add in largest part 
        ans = max(ans , solve(ind+1,diff+r[ind],r,dp));

        // add in small art

        ans = max(ans, min(r[ind],diff)+solve(ind+1, abs(diff-r[ind]),r,dp));

        return dp[ind][diff]=ans;
    }
    int tallestBillboard(vector<int>& rods) 
    {
        int n = rods.size();
        int tot = accumulate(rods.begin(),rods.end(),0);

        vector<vector<int>>dp(n, vector<int>(tot+1,-1));

        return solve(0,0,rods, dp);
    }
};