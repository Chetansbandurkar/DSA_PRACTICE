class Solution {
public:
    // #define ll long long
    bool is_palindrome(int i, int j, string&s) {
        // ll j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    int solve(int i, string& s, vector<int>& dp) {
        if (i == s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int mn_cost = INT_MAX;
        for (int j = i; j < s.size(); j++) {
            if (is_palindrome(i, j, s)) {
                int cost = 1 + solve(j + 1, s, dp);
                mn_cost = min(cost, mn_cost);
            }
        }

        return dp[i] = mn_cost;
    }
    int minCut(string s) {
        vector<int> dp(s.size() + 1, -1);
        // thinfk about the last char we are also dividing lastly
        return solve(0, s, dp) - 1;
    }
};