
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

    Trie() {
        root = new TrieNode();
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

    bool search(string pref, TrieNode* cur) {
        for (int i = 0; i < pref.size(); i++) {
            if (pref[i] == '.') {
                for (auto node : cur->child) {
                    if (node != nullptr &&
                        search(pref.substr(i + 1), node)) {
                        return true;
                    }
                }

                return false;
            }

            int index = pref[i] - 'a';

            if (cur->child[index] == nullptr) {
                return false;
            }

            cur = cur->child[index];
        }

        return cur->isEnd;
    }

    bool search(string pref) {
        return search(pref, root);
    }
};

class WordDictionary {
public:
    Trie* t;

    WordDictionary() {
        t = new Trie();
    }

    void addWord(string word) {
        t->insert(word);
    }

    bool search(string word) {
        return t->search(word);
    }
};