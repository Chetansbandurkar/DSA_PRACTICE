class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long n = nums.size();
        vector<int> lg(n, -1);
        vector<int> rg(n, -1);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            lg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            rg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (lg[i] != -1 && rg[i] != -1)
                ans++;
        }
        return ans;
    }
};