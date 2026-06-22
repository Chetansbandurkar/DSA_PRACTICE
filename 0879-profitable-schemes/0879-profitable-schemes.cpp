class Solution {
public:
    int mp;
    int n;
    int mod = 1e9 + 7;
    int solve(int ind, int tot, int prof, vector<int>& g, vector<int>& p,
              vector<vector<vector<int>>>& dp) {
        if (ind >= g.size())
            return prof >= mp && tot <= n ? 1 : 0;
        if (tot > n)
            return 0;
        if (dp[ind][tot][prof] != -1)
            return dp[ind][tot][prof];

        // inc
        int inc = solve(ind + 1, tot + g[ind],
                        prof + p[ind] > mp ? mp : prof + p[ind], g, p, dp);
        int exc = solve(ind + 1, tot, prof, g, p, dp);

        return dp[ind][tot][prof] = (inc + exc) % mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& g,
                          vector<int>& p) {
        mp = minProfit;
        this->n = n;
        int m = g.size();
        int tot = accumulate(p.begin(), p.end(), 0);
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n + 1, vector<int>(mp+1, -1)));

        return solve(0, 0, 0, g, p, dp) % mod;
    }
};