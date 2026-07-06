class Solution {
public:
    int openLock(vector<string>& d, string target) {
        set<string> st(d.begin(), d.end());
        queue<string> q;
        string start = "0000";
        if(st.count(start)) return -1;
        q.push(start);
        int lvl = 0;
        st.insert(start);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string str = q.front();
                q.pop();
                if (str == target)
                    return lvl;
                for (int i = 0; i < 4; i++) {
                    char c = str[i];
                    char inc = c == '9' ? '0' : c + 1;
                    char dec = c == '0' ? '9' : c - 1;
                    str[i] = inc;
                    if (!st.count(str)) {
                        q.push(str);
                        st.insert(str);
                    }
                    str[i] = dec;
                    if (!st.count(str)) {
                        q.push(str);
                        st.insert(str);
                    }
                    str[i] = c;
                }
            }
            lvl++;
        }
        return -1;
    }
};