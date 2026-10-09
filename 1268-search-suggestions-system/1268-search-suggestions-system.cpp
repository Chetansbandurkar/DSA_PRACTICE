class TrieNode {
    public:
    TrieNode* child[26];
    vector<string> suggestions;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
    public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string s) {
        TrieNode* cur = root;
        for (auto it : s) {
            int index = it - 'a';
            if (cur->child[index] == nullptr) {
                cur->child[index] = new TrieNode();
            }

            cur = cur->child[index];
            if (cur->suggestions.size() < 3) {
                cur->suggestions.push_back(s);
            }
        }
    }

    vector<string> getSugesstions(string pref) {
        TrieNode* cur = root;
        for (auto it : pref) {
            int index = it - 'a';
            if (cur->child[index] == nullptr) {
                return {};
            }

            cur = cur->child[index];
        }
        return cur->suggestions;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p,
                                             string searchWord) {

        sort(p.begin(), p.end());
        vector<vector<string>> ans;

        Trie* t = new Trie();

        for (auto it : p) {
            t->insert(it);
        }

        string s = "";
        for (auto it : searchWord) {
            s += it;
            ans.push_back(t->getSugesstions(s));
        }

        return ans;
    }
};