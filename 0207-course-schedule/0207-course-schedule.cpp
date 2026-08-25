class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        queue<int>q;
        vector<int>ind(n);
        vector<vector<int>>g(n);
        for(auto it : p){
            g[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }

        vector<int>topo;


        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);

            }
        }

        // vector<int>topo;

        while(!q.empty()){
            auto u = q.front();q.pop();
            topo.push_back(u);

            for(auto v : g[u]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v);
                }
            }
        }

        return topo.size()==n;
    }
};