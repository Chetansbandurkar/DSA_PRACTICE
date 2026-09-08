class Solution {
public:
    bool isPal(int i, int j, string &s) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, vector<int>& dp, string& s) {
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int mn = INT_MAX;
        // int ans = 0;
        for (int j = i; j < s.size(); j++) {
            if (isPal(i, j, s)) {
                int ans = 1 + solve(j + 1, dp, s);
                mn = min(mn, ans);
            }
        }
        return dp[i] = mn;
    }
    int minCut(string s)
     {
        vector<int>dp(s.size()+1,-1);
        return solve(0,dp,s)-1;
     }
};