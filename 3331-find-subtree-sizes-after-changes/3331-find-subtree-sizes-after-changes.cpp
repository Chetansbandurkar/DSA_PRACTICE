class Solution {
public:
    vector<int> ans;
    void dfs(int u, vector<int> last, vector<int>& p, vector<vector<int>>& adj,
             string& s) {
        int c = s[u] - 'a', old = last[c];
        if (u >= 1 && old != -1)
            p[u] = old;
        last[c] = u;
        for (auto v : adj[u]) {
            dfs(v, last, p, adj, s);
        }
    }
    int calc(int u, vector<vector<int>>& adj) {
        ans[u] = 1;
        for (auto it : adj[u]) {
            ans[u] += calc(it, adj);
        }
        return ans[u];
    }
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        // dfs for -> changing parent
        // calculate on new parent arrat;
        int n = p.size();
        vector<int> last(26, -1); // have we seen tha same char before
        vector<vector<int>> adj(n), tree(n);
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }
        // dfs
        dfs(0, last, p, adj, s);
        for (int i = 1; i < n; i++) {
            tree[p[i]].push_back(i);
        }
        ans.resize(n);
        calc(0, tree);
        return ans;
    }
};