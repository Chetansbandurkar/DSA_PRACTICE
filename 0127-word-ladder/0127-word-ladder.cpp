class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> canUsed(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        set<string> seen;
        seen.insert(beginWord);
        int ans = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string str = q.front();
                q.pop();
                if (str == endWord)
                    return ans;
                for (int i = 0; i < str.size(); i++) {
                    char cc = str[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (canUsed.count(str) && !seen.count(str)) {
                            q.push(str);
                            seen.insert(str);
                        }
                        str[i] = cc;
                    }
                }
            }
            ans++;
        }

        return 0;
    }
};