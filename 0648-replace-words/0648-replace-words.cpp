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

    bool isValidRoot(string pre) {
        TrieNode* cur = root;

        for (auto it : pre) {
            int index = it - 'a';
            if (cur->child[index] == nullptr) {
                return false;
            }

            cur = cur->child[index];
        }

        return cur->isEnd;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {

        Trie* t = new Trie();

        for (auto it : dictionary) {
            t->insert(it);
        }

        string ans = "";
        string tmp = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                if (ans.empty()) {
                    ans = tmp;
                } else {
                    ans += ' ' + tmp;
                }
                while (i < s.size() && s[i] == ' ')
                    i++;
                tmp = "";
                continue;
            }
            tmp += s[i];

            if (t->isValidRoot(tmp)) {
                if (ans.empty()) {
                    ans = tmp;
                } else {
                    ans += ' ' + tmp;
                }
                i++;
                while (i < s.size() && s[i] != ' ')
                    i++;
                tmp = "";
            }

            i++;
        }

        if (!tmp.empty()) {
            if (ans.empty()) {
                ans = tmp;
            } else {
                ans += ' ' + tmp;
            }
        }

        return ans;
    }
};