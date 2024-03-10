class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& a) {
        int n = a.size();
        vector<string> ans;
        vector<unordered_set<string>> v(n);
        for (int i = 0; i < a.size(); i++) {
            string s = a[i];
            for (int j = 0; j < s.size(); j++) {
                string tmp = "";
                for (int k = j; k < s.size(); k++) {
                    tmp += s[k];
                    // cout<<tmp<<endl;
                    v[i].insert(tmp);
                }
            }
        }
        int i = 0;
        // for(auto &it:v[0])cout<<it<<" ";
        for (int i = 0; i < n; i++) {
            int ln = INT_MAX;
            string a = "";
            for (auto& it : v[i]) {
                // cout<<it<<" ";
                bool f = true;
                for (int j = 0; j < n; j++) {
                    if (i != j && v[j].find(it) != v[j].end()) {
                        f = false;
                        break;
                    }
                }
                if (f) {

                    if ((ln > it.length()) || a.empty()) {
                        ln = it.length();
                        a = it;
                    } else if (ln == it.length()) {
                        if (a > it) {
                            a = it;
                        }
                    }
                }
            }
            if (!a.empty())
                ans.push_back(a);
            else
                ans.push_back("");
        }

        return ans;
    }
};