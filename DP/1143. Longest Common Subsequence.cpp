class Solution {
public:
    // int dp[1001][1001];
    // int solve(string& s, string& t, int i, int j) {
    //     if (i >= s.size() || j >= t.size()) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int a = 0;
    //     if (s[i] == t[j]) {
    //         a = 1 + solve(s, t, i + 1, j + 1);
    //     } else {
    //         a = max(solve(s, t, i + 1, j), solve(s, t, i, j + 1));
    //     }

    //     return dp[i][j] = a;
    // }
    int tab(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int a = 0;
                if (s[i] == t[j]) {
                    a = 1 + dp[i+1][j+1];
                } else {
                    a = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=a;
            }
        }

        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp, -1, sizeof(dp));
        // return solve(text1, text2, 0, 0);
        return tab(text1,text2);
    }
};