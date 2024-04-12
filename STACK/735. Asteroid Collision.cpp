class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for (auto x : ast) {
            if (x < 0) {
                // value ko kab push kar sakta he and
                // kb pop out kr sakta he bro;
                while (!st.empty() && st.top() > 0 && st.top() < abs(x)) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(x);
                } else if (st.top() == abs(x)) {
                    st.pop();
                }
            } else
                st.push(x);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};