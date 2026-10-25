class DSU {
public:
    vector<int> sz;
    vector<int> parent;
    int component;
    DSU(int n) {
        sz.resize(n+1, 1);
        parent.resize(n+1);
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU alice(n);
        DSU bob(n);
        int require = 0;
        // type 3;

        for (auto it : edges) {
            if (it[0] == 3) {
                if (bob.unite(it[1], it[2])) {
                    require++;
                    alice.unite(it[1], it[2]);
                }
            }
        }

        // type 2 , 3;

        for (auto it : edges) {
            if (it[0] == 1 && alice.unite(it[1], it[2])) {
                alice.unite(it[1], it[2]);
                require++;
            } else if (it[0] == 2 && bob.unite(it[1], it[2])) {
                bob.unite(it[1], it[2]);
                require++;
            }
        }

        if (bob.isComponent() && alice.isComponent()) {
            return edges.size() - require;
        }

        return -1;
    }
};