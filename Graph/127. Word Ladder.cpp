class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // USE THE  BFS QUEUE
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        // ot worksa as visited array in bfs
        st.erase(beginWord);

        // TIME COMPLEXITY
        // N* WORDLEN*26 * log N to erase tthe string AT WORST

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord)
                return step;
            // want to change the value at each index
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    // agar mil gya to 
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};