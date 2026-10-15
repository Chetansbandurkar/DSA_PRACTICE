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

    Trie() { root = new TrieNode(); }

    void insert(string word, int ind) {
        TrieNode* cur = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (cur->child[index] == nullptr) {
                cur->child[index] = new TrieNode();
            }

            cur = cur->child[index];
            cur->list.push_back(ind);
        }

        cur->isEnd = true;
    }

    vector<int> searchString(string s) {
        TrieNode* cur = root;
        for (auto it : s) {
            int index = it - 'a';
            if (cur->child[index] == nullptr) {
                return {};
            }

            cur = cur->child[index];
        }

        return cur->list;
    }
};

class WordFilter {
public:
    Trie* pt;
    Trie* st;
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        pt = new Trie();
        st = new Trie();
        for (int i = 0; i < words.size(); i++) {
            pt->insert(words[i], i);
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            st->insert(rev, i);
        }
    }

    int f(string pref, string suff) {
        string key = pref + "-" + suff;
        if (mp.find(key) != mp.end())
            return mp[key];
        vector<int> prefL = pt->searchString(pref);
        reverse(suff.begin(), suff.end());
        vector<int> suffL = st->searchString(suff);
        int i = prefL.size() - 1;
        int j = suffL.size() - 1;
        while (i >= 0 && j >= 0) {
            if (prefL[i] == suffL[j])
                return mp[key] = prefL[i];
            if (prefL[i] > suffL[j])
                i--;
            else
                j--;
        }

        return mp[key] = -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */