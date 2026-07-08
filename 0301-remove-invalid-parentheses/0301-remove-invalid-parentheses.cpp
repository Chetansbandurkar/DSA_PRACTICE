class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        queue<string> q;
        vector<string> ans;
        q.push(s);
        set<string> seen;
        seen.insert(s);
        while (!q.empty()) {

            int sz = q.size();
            bool valid = false;
            while (sz--) {
                string s = q.front();
                int r = 0;
                int l = 0;
                bool strV = true;
                q.pop();
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] == '(')
                        l++;
                    else if (s[i] == ')')
                        l--;
                    if (l < 0) {
                        strV = false;
                        break;
                    }
                }
                if (strV && l == 0) {
                    ans.push_back(s);
                    valid = true;
                }
                if (valid)
                    continue;
                string tmp;
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] == '(' || s[i] == ')') {
                        string val = s.substr(i + 1, s.size() - i - 1);
                        if (!seen.count(tmp + val)) {
                            q.push(tmp + val);
                            seen.insert(tmp+val);
                        }
                        cout << tmp + val << endl;
                    }
                    tmp.push_back(s[i]);
                }
            }

            if (valid)
                return ans;
        }

        return ans;
    }
};