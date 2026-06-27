class Solution {
public:
    int longestAwesome(string s) {
        map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        int mask = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            auto it = s[i];
            mask ^= (1 << (it - '0'));
            if (mp.find(mask) != mp.end()) {
                ans = max(ans, i - mp[mask]);
            } else {
                mp[mask] = i;
            }
            for (int j = 0; j < 10; j++) {
                if (mp.find(mask ^ (1 << j)) != mp.end()) {
                    ans = max(ans, i - mp[mask ^ (1 << j)]);
                }
            }
        }

        return ans;
    }
};