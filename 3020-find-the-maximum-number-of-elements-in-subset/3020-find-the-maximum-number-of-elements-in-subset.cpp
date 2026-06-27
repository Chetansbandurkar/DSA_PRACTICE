class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }
        long long ans = 1;
        for (auto it : nums) {
            if (it == 1)
                continue;

            long long curAns=1;
            while((int)sqrt(it)*(int)sqrt(it)==it && freq[sqrt(it)]>=2)
            {
                curAns+=2;
                it=sqrt(it);
            }
            ans= max(ans, curAns);
        }

        ans = max(1LL*ans , freq[1]%2 ? 1LL*freq[1] :1LL* freq[1]-1);

        return ans ;
    }
};