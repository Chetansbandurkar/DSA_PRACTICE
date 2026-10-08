class TrieNode {
public:
    TrieNode* child[26];
    int sum = 0;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        sum = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string s, int val) {
        TrieNode* cur = root;

        int n = s.size();

        for (auto it : s) {
            int index = it - 'a';

            if (cur->child[index] == nullptr) {
                cur->child[index] = new TrieNode();
            }
            // cur->sum += val;
            cur = cur->child[index];
            cur->sum += val;
        }
    }
    int findSum(string pre) {
        TrieNode* cur = root;
        int val = 0;
        for (auto it : pre) {
            int index = it - 'a';
            if (cur->child[index] == nullptr) {
                return 0;
            }
            // val = cur->sum;
            cur = cur->child[index];
        }

        return cur->sum;
    }
};
class MapSum {
public:
    Trie* t;
    map<string, int> mp;
    MapSum() { t = new Trie(); }

    void insert(string key, int val) {
        int del = 0;

        if (mp.find(key) != mp.end()) {
            del = val - mp[key];
            mp[key] = val;
        } else {
            mp[key] = val;
            del = val;
        }

        t->insert(key, del);
    }

    int sum(string prefix) { return t->findSum(prefix); }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */