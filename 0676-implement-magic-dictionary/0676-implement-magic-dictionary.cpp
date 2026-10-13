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

    bool check(string word, int ind, TrieNode* cur, bool changed) {
        for (int i = ind; i < word.size(); i++) {
            if (!changed) {
                for (int j = 0; j < 26; j++) {
                    if (cur->child[j] && j != word[i] - 'a') {
                        if (check(word, i + 1, cur->child[j], true)) {
                            return true;
                        }
                    }
                }
            }

            if (cur->child[word[i] - 'a'])
                cur = cur->child[word[i] - 'a'];
            else
                return false;
        }

        return cur->isEnd && changed;
    }
    bool checkIfWordIsValid(string word) { return check(word, 0, root, 0); }
};

class MagicDictionary {
public:
    Trie* t;
    MagicDictionary() { t = new Trie(); }

    void buildDict(vector<string> dictionary) {
        for (auto it : dictionary) {
            t->insert(it);
        }
    }

    bool search(string searchWord) { return t->checkIfWordIsValid(searchWord); }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */