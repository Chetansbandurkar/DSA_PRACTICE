class Solution {
public:
    int calDist(char a, char b) {
        int val = abs((a - '0') - (b - '0'));
        return min(val, 10 - val);
    }
    int minRotations(int n, string s) {
        // int n = s.size();

        vector<int> pref(n), suf(n);

        pref[0] = calDist('0', s[0]);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + calDist(s[i - 1], s[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + calDist(s[i], s[i + 1]);
        }

        int ans = pref[n - 1];

        for (int i = 0; i < n; i++) {
            int val;
            if (i == 0) {
                val = calDist('0', s[n - 1]) + suf[0];
            } else {
                val = pref[i - 1] + calDist(s[i - 1], s[n - 1]) + suf[i];
            }

            ans = min(ans, val);
        }

        return ans;
    }
};