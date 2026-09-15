class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        long long mod = 1e9 + 7;
        vector<long long> last(26, 0);

        long long dp = 1;
        for (auto c : s) {
            int val = c - 'a';
            long long nDp = (dp * 2) % mod;
            nDp = (nDp - last[val] + mod) % mod;
            last[val] = dp;
            dp = nDp;
        }

        return (dp - 1 + mod) % mod;
    }
};