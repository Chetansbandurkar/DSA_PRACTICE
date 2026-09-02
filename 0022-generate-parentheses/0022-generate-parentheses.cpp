class Solution {
public:
    vector<string> ans;
    void formValidCombination(int open, int close, string s) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        if (open > 0) {
            s.push_back('(');
            formValidCombination(open - 1, close, s);
            s.pop_back();
        }

        if (close > open) {
            s.push_back(')');
            formValidCombination(open, close - 1, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        formValidCombination(n, n, s);
        return ans;
    }
};