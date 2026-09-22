class Dsu {
public:
    vector<int> size;
    vector<int> parent;
    Dsu(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    bool unite(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px == py)
            return false;

        if (size[px] > py) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px];
        }

        return true;
    }
};

class Solution {
public:
    bool canBeSame(string& s, string& t) {
        int n = s.size();
        int dif = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i])
                dif++;
        }
        return dif == 0 || dif == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int component = n;

        Dsu dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (canBeSame(strs[i], strs[j])) {
                    if (dsu.unite(i, j)) {
                        component--;
                    }
                }
            }
        }

        return component;
    }
};