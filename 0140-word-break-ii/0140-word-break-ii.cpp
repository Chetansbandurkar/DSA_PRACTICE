class Solution {
public:
    vector<string> ans;
    bool check(string s, vector<string>& dict) {
        for (auto it : dict) {
            if (it == s) {
                return true;
            }
        }
        return false;
    }

    void solve(int ind, string& s, string tmp, vector<string>& dict) {
        if (ind == s.size()) {
            ans.push_back(tmp);
            return;
        }

        string t = "";
        for (int i = ind; i < s.size(); i++) {
            t += s[i];
            if (check(t, dict)) {
                if(tmp.empty())
                solve(i+1,s,t,dict);
                else
                solve(i + 1,s, tmp + " " + t, dict);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        solve(0, s,"", wordDict);
        return ans;
    }
};