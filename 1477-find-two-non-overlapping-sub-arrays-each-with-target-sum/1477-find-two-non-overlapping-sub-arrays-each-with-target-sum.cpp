class Solution {
public:
#define ll long long
    ll solve(int ind, int k, int& t, vector<ll>& pres,
             vector<vector<ll>>& dp) {

        if (k == 0)
            return 0;
        if (ind >= pres.size())
            return INT_MAX;
        if (dp[ind][k] != -1)
            return dp[ind][k];

        ll ans = solve(ind + 1, k, t, pres, dp); // starting again with rem K;
        auto lb = lower_bound(pres.begin(), pres.end(), pres[ind - 1] + t);
        if (lb != pres.end() && *lb == pres[ind - 1] + t) {
            int pos = lb - pres.begin();
            ans = min(ans, pos - ind + 1 + solve(pos + 1, k - 1, t, pres, dp));
        }

        return dp[ind][k] = ans;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<ll>> dp(n + 2, vector<ll>(3, -1));
        vector<ll> pres(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pres[i] = pres[i - 1] + arr[i - 1];
        }

        ll ans = solve(1, 2, target, pres, dp);
        if (ans >= INT_MAX)
            return -1;

        return ans;
    }
};