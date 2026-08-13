class DSU {
public:
    vector<int> size, parent;

    DSU(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            size[i] = 1;       // FIX 1
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        int sx = Find(x);
        int sy = Find(y);

        if (sx == sy)
            return;

        if (size[sx] > size[sy]) {
            parent[sy] = sx;       // FIX 2
            size[sx] += size[sy];
        } else {
            parent[sx] = sy;       // FIX 3
            size[sy] += size[sx];
        }
    }

    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }

    void reset(int x) {
        parent[x] = x;
        size[x] = 1;
    }
};


class Solution {
public:
    using int2 = pair<int, int>;

    vector<int> findAllPeople(
        int n,
        vector<vector<int>>& meetings,
        int firstPerson
    ) {
        vector<int2> meet_time[100001];

        int tMax = -1;

        for (auto& meet : meetings) {
            int x = meet[0];
            int y = meet[1];
            int t = meet[2];

            meet_time[t].emplace_back(x, y);

            tMax = max(tMax, t);
        }

        DSU uf(n);

        uf.Union(0, firstPerson);

        for (int t = 0; t <= tMax; t++) {

            for (auto& [x, y] : meet_time[t]) {
                uf.Union(x, y);
            }
            vector<pair<int, int>> roots;

            for (auto& [x, y] : meet_time[t]) {
                roots.push_back({x, uf.Find(x)});
                roots.push_back({y, uf.Find(y)});
            }

            int secretRoot = uf.Find(0);
            for (auto& [person, root] : roots) {

                if (root != secretRoot) {
                    uf.reset(person);
                }
            }
        }

        vector<int> list = {0};

        for (int i = 1; i < n; i++) {
            if (uf.connected(0, i))
                list.push_back(i);
        }

        return list;
    }
};