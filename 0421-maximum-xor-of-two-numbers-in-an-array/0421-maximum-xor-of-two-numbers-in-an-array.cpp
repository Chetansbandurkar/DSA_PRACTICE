class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* cur = root;
        for (int i = 30; i >= 0; i--) {
            int val = (num >> i) & 1;
            if (cur->child[val] == nullptr) {
                cur->child[val] = new TrieNode();
            }
            cur = cur->child[val];
        }
    }

    int getMaxXor(int num) {
        TrieNode* cur = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--)

        {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;

            if (cur->child[opp] != nullptr) {
                ans = ans | (1 << i);
                cur = cur->child[opp];
            } else {
                cur = cur->child[bit];
            }
        }

        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie* t = new Trie();
        for (auto it : nums) {
            t->insert(it);
        }
        int ans = 0;
        for (auto it : nums) {
            ans = max(ans, t->getMaxXor(it));
        }

        return ans;
    }
};