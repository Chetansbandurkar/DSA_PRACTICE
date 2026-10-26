class DSU {
public:
    vector<int> sz;
    vector<int> parent;
    int component;
    DSU(int n) {
        sz.resize(n + 1, 1);
        parent.resize(n + 1);
        component = n;
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findP(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findP(parent[x]);
    }
    bool unite(int x, int y) {
        int px = findP(x);
        int py = findP(y);

        if (px == py)
            return false;

        if (sz[px] > sz[py]) {
            parent[py] = px;
            sz[px] += sz[py];
        } else {
            parent[px] = py;
            sz[py] += sz[px];
        }
        component--;
        return true;
    }
    bool isComponent() { return component == 1; }
};

class Solution {
public:
    vector<bool> areConnected(int n, int t, vector<vector<int>>& q) {
        DSU dsu(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    if (j > t)
                        dsu.unite(i, j);
                    if ((i / j) > t)
                        dsu.unite(i / j, i);
                }
            }
        }

        vector<bool> ans(q.size());
        int ind = 0;
        for (auto it : q) {
            ans[ind++] = dsu.findP(it[0]) == dsu.findP(it[1]);
        }

        return ans;
    }
};