class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    string ans;

    Trie() {
        root = new TrieNode();
        ans = "";
    }

    void insert(string s) {
        TrieNode* cur = root;

        for (char ch : s) {
            int index = ch - 'a';

            if (cur->child[index] == nullptr) {
                cur->child[index] = new TrieNode();
            }

            cur = cur->child[index];
        }

        cur->isEnd = true;
    }
    void dfs(TrieNode* cur, string& tmp) {

        for (int i = 0; i < 26; i++) {
            if (cur->child[i] != nullptr && cur->child[i]->isEnd) {
                tmp.push_back(i + 'a');
                if (tmp.size() > ans.size()) {
                    ans = tmp;
                }

                dfs(cur->child[i], tmp);
                tmp.pop_back();
            }
        }
    }

    void findLongestString() {
        string tmp = "";
        // ans = "";
        dfs(root, tmp);
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* t = new Trie();

        for (auto it : words) {
            t->insert(it);
        }
        t->findLongestString();
        return t->ans;
    }
};