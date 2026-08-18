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

    bool isSame(int x, int y) { return findP(x) == findP(y); }
    bool unite(int x, int y) {
        int px = findP(x);
        int py = findP(y);

        if (px == py)
            return 0;

        if (s[px] > s[py]) {
            s[px] += s[py];
            p[py] = px;
        } else {
            s[py] += s[px];
            p[px] = py;
        }

        return 1;
    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& e, int k) {
        DSU dsu(n);
        // return time t>= time  ( when you have  already remove tha edges with
        // time greater>>= t)

        sort(e.begin(), e.end(),
             [](vector<int>& a, vector<int>& b) { return a[2] > b[2]; });

        int ct = n;
        if (k > n)
            return -1;
        int res = 0;
        for (int i = 0; i < e.size(); i++) {
            bool f = dsu.unite(e[i][0], e[i][1]);
            if (f)
                ct--;
            if (ct >= k)
                res = i + 1;
            else
                break;
        }

        return res == e.size() ? 0 : e[res][2];
    }
};