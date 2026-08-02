class Solution {
public:
    vector<int> countTasks(vector<int>& t, vector<int>& s) {
        int n = t.size();
        vector<long long> pre(n, 0);
        pre[0] = t[0];
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] + t[i]);
        }
        vector<int> ans(s.size(), 0);
        long long alreadyDone = 0;
        for (int i = 0; i < s.size(); i++) {
            long long val = s[i];

            auto it = lower_bound(pre.begin(), pre.end(), val + alreadyDone) -
                      pre.begin();
            if (it == n) {
                ans[i] = 0;
                alreadyDone = 0;
            } else if (pre[it] == alreadyDone + val) {
                ans[i] = n - 1 - it;

                if (it == n - 1)
                    alreadyDone = 0;
                else
                    alreadyDone = pre[it];
            } else {
                ans[i] = n - it;
                alreadyDone += val;
            }

            // cout << it << " ";
        }

        return ans;
    }
};