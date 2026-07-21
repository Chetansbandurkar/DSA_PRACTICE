class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>g(n);
        vector<int>topo;
        vector<int>ind(n,0);
        for(auto it: p){
            g[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: g[node]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }

        return topo.size()==n;
    }
};