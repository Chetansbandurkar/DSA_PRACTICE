class Solution {
public:
    void calCostForNode(int node, int par, vector<vector<pair<int, int>>>& g,
                        vector<int>& cost) {
        for (auto it : g[node]) {
            if (it.first == par)
                continue;
            int wt = it.second;
            cost[0] += wt;
            calCostForNode(it.first, node, g, cost);
        }
    }

    void reRerootTechForOtherNodesCost(int node, int par,
                                       vector<vector<pair<int, int>>>& g,
                                       vector<int>& cost) {
        for (auto it : g[node]) {
            if (it.first == par)
                continue;

            int wt = it.second;
            int valToBeAdded = wt == 0 ? 1 : -1;
            cost[it.first] = cost[node] + valToBeAdded;
            reRerootTechForOtherNodesCost(it.first, node, g, cost);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);

        for (auto it : edges) {
            g[it[0]].push_back({it[1], 0});
            g[it[1]].push_back({it[0], 1});
        }
        vector<int> cost(n, 0);
        calCostForNode(0, -1, g, cost); // dfs -> cost for the 0th node
        reRerootTechForOtherNodesCost(0, -1, g, cost); //rerroot technique for other node's

        return cost;
    }
};