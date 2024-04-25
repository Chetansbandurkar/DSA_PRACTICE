class Solution {
public:
    int solve(string&s, int pr, int& k, int ind, vector<vector<int>>& dp) {
        if (ind >= s.size())
            return 0;
        if (dp[ind][pr+1] != -1)
            return dp[ind][pr+1];
        int inc = 0;
        if (pr == -1 || abs(pr - (s[ind] - 'a')) <= k)
            inc = 1 + solve(s, s[ind] - 'a', k, ind + 1, dp);

        int exc = solve(s, pr, k, ind + 1, dp);

        return dp[ind][pr+1] = max(inc, exc);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size(),vector<int>(27,-1));
        return solve(s, -1, k, 0, dp);
    }
};