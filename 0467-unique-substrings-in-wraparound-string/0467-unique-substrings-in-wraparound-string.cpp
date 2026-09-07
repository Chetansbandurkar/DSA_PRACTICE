class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        int mx = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)) {
                mx++;
            } else {
                mx = 1;
            }

            cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'], mx);
        }

        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};