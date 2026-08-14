class DSU {
public:
    vector<int> s, p;

    DSU(int n) {
        s.resize(n + 1);
        p.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            s[i] = 1;
            p[i] = i;
        }
    }

    int findP(int x) {
        if (x == p[x])
            return x;

        return p[x] = findP(p[x]);
    }

    void unite(int x, int y) {
        int px = findP(x);
        int py = findP(y);

        if (px == py)
            return;

        if (s[px] > s[py]) {
            s[px] += s[py];
            p[py] = px;
        } else {
            s[py] += s[px];
            p[px] = py;
        }
    }

    void reset(int x) {
        p[x] = x;
        s[x] = 1;
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& res,
                                vector<vector<int>>& req) {
        vector<bool> ans;
        DSU dsu(n);

        for (auto it : req) {
            vector<int> tp, ts;
            tp = dsu.p;
            ts = dsu.s;
            int x = it[0], y = it[1];
            dsu.unite(x, y);
            bool valid = 1;
            for (auto it : res) {
                int px = dsu.findP(it[0]);
                int py = dsu.findP(it[1]);

                if (px == py) {
                    valid = false;
                    ans.push_back(false);
                    break;
                }
            }

            if (valid) {
                ans.push_back(true);
            } else {
                dsu.p = tp;
                dsu.s = ts;
            }
        }

        return ans;
    }
};