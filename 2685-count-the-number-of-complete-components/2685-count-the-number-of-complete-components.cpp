class Solution {
public:
    void dfs(int node, unordered_set<int>& comp, unordered_set<int>& vis, vector<vector<int>>& g) {
        comp.insert(node);
        vis.insert(node);
        for (auto &it : g[node]) {
            if (!vis.count(it)) {
                dfs(it, comp, vis, g);
            }
        }
    }
    bool isCompleteComponent(unordered_set<int>&comp, vector<vector<int>>&g){

        for(auto &it : comp){
            if(g[it].size()!=comp.size()-1) return false;
        }

        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for (auto &it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        int count = 0;
       unordered_set<int>vis;
        for(int i=0;i<n;i++){
            if(!vis.count(i)){
                unordered_set<int>comp;
                dfs(i,comp, vis,g);
                if(isCompleteComponent(comp, g))count++;
            }
        }

        return count;
    }
};