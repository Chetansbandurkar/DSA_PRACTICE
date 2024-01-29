class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // EVERY No is the square of previois ,&& sq.root of prev
        // middle no accure once length of subset should be ood
        // max no is the
        // 10^9->10^5(upper boudn taken)->10^3->10^1->3->1;
        // so maximum 12->13 len subset can form\
        // so we will do conside every element as middle element s
        // if it iperfect sq root && Search for sq root of it wose freq>=2
        // bas ho gaya bhai
        map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }
        int ans = 0;
        for (auto it : nums) {
            if (it == 1)
                continue;
            int curr_ans = 1;
            while ((int)sqrt(it) * (int)sqrt(it) == it && freq[sqrt(it)] >= 2) {
                curr_ans += 2;
                it = sqrt(it);
            }
            ans = max(ans, curr_ans);
        }
        ans = max(ans, freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]);
        return ans;
    }
};
