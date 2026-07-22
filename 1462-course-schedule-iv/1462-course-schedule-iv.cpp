class Solution {
public:
    vector<bool> checkIfPrerequisite(int nc, vector<vector<int>>& p,
                                     vector<vector<int>>& que) {
        vector<vector<int>> g(nc);
        vector<int> ind(nc);
        for (auto it : p) {
            g[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < nc; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        map<int, set<int>> mp;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto it : g[node]) {
                ind[it]--;
                mp[it].insert(node);
                for (auto val : mp[node]) {
                    mp[it].insert(val);
                }

                if (ind[it] == 0) {
                    q.push(it);
                }
            }
        }
        vector<bool> ans(que.size(), false);
        int i = 0;
        for (auto qr : que) {

            if (mp[qr[0]].count(qr[1])) {
                ans[i] = true;
            }
            i++;
        }

        return ans ;
    }
};