class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int l = *max_element(w.begin(),w.end());
        int n = w.size();
        int h = accumulate(w.begin(), w.end(),0);
        int ans = h;
        while (l <= h) {
            int md = (l + h) >> 1;
            int sum = 0;
            int d = 0;
            for (int i = 0; i < n; i++) {
                sum += w[i];
                if (sum > md) {
                    sum = w[i];
                    d++;
                }
            }
            if (sum > 0)
                d++;
            if (d <= days) {
                h = md - 1;
                ans = md;
            } else {
                l = md + 1;
            }
        }

        return ans;
    }
};