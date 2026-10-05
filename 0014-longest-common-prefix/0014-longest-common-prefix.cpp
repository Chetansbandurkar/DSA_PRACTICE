class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int prefixCount;

    TrieNode() {
        isEnd = false;
        prefixCount = 0;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    // ---------------- INSERT ----------------
    void insert(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int index = c - 'a';

            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode();
            }

            cur = cur->children[index];

            // One or more word has this prefix
            cur->prefixCount++;
        }

        cur->isEnd = true;
    }
    string solve(vector<string>& str) {
        for (auto it : str) {
            insert(it);
        }

        string ans = "";

        TrieNode* cur = root;

        while (true) {

            if (cur->isEnd)
                return ans;

            int nxtIndex = 0;
            int cnt = 0;

            for (int i = 0; i < 26; i++) {

                if (cur->children[i] != nullptr) {
                    cnt++;
                    nxtIndex = i;
                }
            }

            if (cnt != 1)
                return ans;

            ans += char('a' + nxtIndex);
            cur = cur->children[nxtIndex];
        }

        return ans ;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        Trie * t = new Trie();
        return t->solve(strs);
    }
};