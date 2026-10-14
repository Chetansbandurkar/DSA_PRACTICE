class TrieNode {
public:
    TrieNode* child[10];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;

        for (char ch : word) {
            int index = ch - '0';

            if (cur->child[index] == nullptr) {
                cur->child[index] = new TrieNode();
            }

            cur = cur->child[index];
        }

        cur->isEnd = true;
    }

    int check(string str) {
        TrieNode* cur = root;
        int ind = 0;

        for (; ind < str.size(); ind++) {
            int index = str[ind] - '0';
            if (cur->child[index]) {
                cur = cur->child[index];
            } else
                break;
        }

        return ind;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t = new Trie();
        for (auto it : arr1) {
            string s = to_string(it);
            t->insert(s);
        }

        int ans = 0;
        for (auto it : arr2) {
            string s = to_string(it);
            ans = max(ans, t->check(s));
        }

        return ans;
    }
};