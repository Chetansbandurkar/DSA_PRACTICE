class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        vector<int> mxTime = time;
        for (auto it : r) {
            g[it[0] - 1].push_back(it[1] - 1);
            indegree[it[1] - 1]++;
        }
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int val = 0;
            auto node = q.front();
            q.pop();

            for (auto it : g[node]) {
                indegree[it]--;
                mxTime[it] = max(mxTime[it], mxTime[node] + time[it]);
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, mxTime[i]);
        }

        return ans;
    }
};