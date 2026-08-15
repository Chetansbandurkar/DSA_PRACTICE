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

    bool isSame (int x, int y)
    {
        return findP(x)==findP(y);
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
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c)
    {
        DSU dsu(n);
        int cnt = 0;
        int comp = n -1;
        for(auto it : c ){
            int x = it[0];
            int y = it[1];

            if(dsu.isSame(x, y)){
                cnt ++ ;
            }
            else{
                comp--;
            }
            dsu.unite(x, y);
        }

        if(comp<=cnt) return comp;

        return -1;
    }
};