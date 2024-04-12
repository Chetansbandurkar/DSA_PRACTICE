class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int mn = a[0][0];
        int mx = a[0][1];
        for (int i = 1; i < a.size();) {
            if (a[i][0] <= mx) {
                mx = max(a[i][1], mx);
                mn = min(a[i][0], mn);
            } else {
                ans.push_back({mn, mx});
                mn = a[i][0];
                mx = a[i][1];
                // else mx = INT_MAX;
            }
            i++;
        }

        if (mx != 0) {
            ans.push_back({mn, mx});
        }

        return ans;
    }
};