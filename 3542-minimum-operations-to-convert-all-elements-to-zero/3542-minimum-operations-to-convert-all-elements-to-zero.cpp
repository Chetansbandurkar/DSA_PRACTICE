class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int res = 0;
        for (auto i : nums) {
            while (!st.empty() && st.top() > i) {
                st.pop();
            }
            if(i==0) continue;

            if (st.empty() || st.top() < i) {
                res++;
                st.push(i);
            }
        }

        return res;
    }
};