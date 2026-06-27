class Solution {
public:
    long long ans = 0;
    void dfs(int mask, int node, unordered_map<int, int>& mp,
             vector<vector<int>>& tree, string& s) {
        mask ^= (1 << (s[node] - 'a'));
        ans+=mp[mask];
        mp[mask]++;
        for(int i=0;i<26;i++){
            ans+=mp[mask^(1<<i)];
        }
        for(auto it:tree[node]){
            dfs(mask,it,mp,tree,s);
        }
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        ans = 0;
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }
        unordered_map<int, int> mp;
        dfs(0, 0, mp, tree, s);
        return ans ;
    }
};