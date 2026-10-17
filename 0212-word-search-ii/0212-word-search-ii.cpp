/*
Think from the words how we can utilize the words .
*/
int n, m;
class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    vector<int> list;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        list = {};
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    int del[5] = {-1, 0, 1, 0, -1};
    Trie() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (cur->child[index] == nullptr) {
                cur->child[index] = new TrieNode();
            }
            cur = cur->child[index];
        }
        cur->isEnd = true;
    }
    bool anyWordStartWithChar(int c) { return root->child[c] != nullptr; }
    void dfs(TrieNode* cur, vector<vector<char>>& board, vector<string>& ans,
             int rr, int cc, string temp, vector<vector<int>>& vis) {
        if (!cur)
            return;
        if (cur->isEnd) {
            ans.push_back(temp);
            cur->isEnd = false;
        }
        vis[rr][cc] = 1;
        for (int i = 0; i < 4; i++) {
            int r = del[i] + rr, c = del[i + 1] + cc;
            if (r >= 0 && r < n && c >= 0 && c < m &&
                cur->child[board[r][c] - 'a'] && !vis[r][c]) {
                dfs(cur->child[board[r][c] - 'a'], board, ans, r, c,
                    temp + board[r][c], vis);
            }
        }
        vis[rr][cc] = 0;
    }

    void check(int ind, vector<vector<char>>& board, vector<string>& ans, int r,
               int c, string tmp, vector<vector<int>>& vis) {
        dfs(root->child[ind], board, ans, r, c, tmp, vis);
    }
    // search for the words while traversing
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* t = new Trie();
        for (auto it : words) {
            t->insert(it);
        }
        n = board.size();
        m = board[0].size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind = board[i][j] - 'a';

                if (t->anyWordStartWithChar(ind)) {
                    t->check(ind, board, ans, i, j, string(1, board[i][j]),
                             vis);
                }
            }
        }

        return ans;
    }
};