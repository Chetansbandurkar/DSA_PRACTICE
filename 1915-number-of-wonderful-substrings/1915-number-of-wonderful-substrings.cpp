class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0);
        long ans = 0;
        int mask = 0;
        count[0] = 1;

        for(auto it : word)
        {
            mask ^= 1 << (it - 'a');
            ans += count[mask];
            for(int i = 0 ; i < 10 ; i++)
            {
                ans += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return ans;
    }
};