class Solution {
public:
    string expand(int l, int r, string s) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string odd = expand(i, i, s);
            string eve = expand(i, i + 1, s);
            if (odd.size() > ans.size())
                ans = odd;
            if (eve.size() > ans.size())
                ans = eve;
        }
        return ans;
    }
};