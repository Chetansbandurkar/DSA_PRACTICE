class Solution {
public:
    int height;
    int calcH(int node, vector<vector<int>>& g) {
        int ans = 1;
        for (auto it : g[node]) {
            ans = max(ans, calcH(it, g) + 1);
        }
        return ans;
    }

    long long solve(int node, int d, vector<vector<int>>& g,
                    vector<int>& nums) {
        long long val = 1LL * nums[node] * (height - d + 1);

        for (auto it : g[node]) {
            val += solve(it, d + 1, g, nums);
        }

        return val;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }

        height = calcH(0, g);

        long long ans = solve(0, 1, g, nums);

        return ans ;
    }
};