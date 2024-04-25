class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(), deadends.end());
        // no need of mean heap or set as we are changint the value
        // by one every time
        queue<string> q;
        string start="0000";
        q.push(start);
        if(st.find(start)!=st.end())return -1;
        int level = 0;
        while (!q.empty()) {
            // int cur=q.front();
            int n = q.size();
            // are bhai tu jitne hoge utne hi check karega n bhai as
            // at each level you can change evry value by one
            // tu kisime bhi change kr sakta he current string ko so try
            // every possible change then return value;
            while (n--) {
                string cur=q.front();
                q.pop();
                if(cur==target)return level;
                for (int i = 0; i < 4; i++) {
                    char ch = cur[i];
                    char inc = ch == '9' ? '1' : ch + 1;
                    char dec = ch == '0' ? '9' : ch - 1;
                    cur[i] = dec;
                    if (st.find(cur) == st.end()) {
                        q.push(cur);
                        st.insert(cur);
                    }
                    cur[i] = inc;
                    if (st.find(cur) == st.end()) {
                        q.push(cur);
                        st.insert(cur);
                    }
                    // restore kr le bhai real vala 
                    cur[i]=ch;
                }
            }
            level++;
        }
        return -1;
    }
};
