class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unite(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return;
        else if (x > y)
            parent[x] = y;
        else
            parent[y] = x;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string b) {

        DSU dsu(27);
        int n = s1.size();

        for (int i = 0; i < n; i++) {
            dsu.unite(s1[i] - 'a', s2[i] - 'a');
        }

        string ans(b.size(), ' ');

        for (int i = 0; i < b.size(); i++) {
            ans[i] = 'a' + dsu.findParent(b[i] - 'a');
        }

        return ans;
    }
};