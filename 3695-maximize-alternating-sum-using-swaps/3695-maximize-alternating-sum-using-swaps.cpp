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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        DSU dsu(n);
        for (auto it : swaps) {
            dsu.unite(it[0], it[1]);
        }

        map<int, multiset<int, greater<long long>>> mp;
        for (int i = 0; i < n; i++) {
            mp[dsu.findP(i)].insert(nums[i]);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans += *mp[dsu.findP(i)].begin();
                mp[dsu.findP(i)].erase(mp[dsu.findP(i)].begin());
            } else {
                auto& st = mp[dsu.findP(i)];
                auto it = prev(st.end());

                ans -= *it;
                st.erase(it);
            }
        }

        return ans;
    }
};