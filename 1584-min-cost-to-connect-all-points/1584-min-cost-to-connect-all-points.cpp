class Solution {
public:
    int calc(vector<int>&a, vector<int>&b){

        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});

        vector<int> vis(n, 0);
        int ans = 0;

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (vis[u])
                continue;

            vis[u] = 1;
            ans += cost;

            for (int v = 0; v < n; v++) {
                pq.push({calc(points[u],points[v]),v});
            }
        }

        return ans ;
    }
};