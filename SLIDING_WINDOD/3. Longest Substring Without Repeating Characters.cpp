class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ln = INT_MIN;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 1 && j <=i) {
                mp[s[j]]--;
                j++;
            }
            ln = max(ln, i-j + 1);
        }

        return ln==INT_MIN?0:ln;
    }
};