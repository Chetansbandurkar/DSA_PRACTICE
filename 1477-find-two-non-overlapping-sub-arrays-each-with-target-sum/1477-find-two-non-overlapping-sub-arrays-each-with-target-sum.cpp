class Solution {
public:
#define ll long long int
    int t[100005][3];
    ll compute(vector<ll>& presum, ll target, int id, ll k, int n) {
        if (k == 0) {
            return 0;
        }
        if (id >= n) {
            return INT_MAX;
        }
        if (t[id][k] != -1) {
            return t[id][k];
        }
        ll ans = compute(presum, target, id + 1, k, n);
        auto lb =
            lower_bound(presum.begin(), presum.end(), presum[id - 1] + target);
        if (lb != presum.end() && *lb == presum[id - 1] + target) {
            int pos = lb - presum.begin();
            ans = min(ans, pos - id + 1 +
                               compute(presum, target, pos + 1, k - 1, n));
        }
        return t[id][k] = ans;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        memset(t, -1, sizeof(t));
        vector<ll> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + arr[i - 1];
        }
        ll ans = compute(presum, target, 1, 2, n + 1);
        if (ans >= INT_MAX) {
            return -1;
        }
        return ans;
    }
};