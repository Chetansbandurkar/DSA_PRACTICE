class Solution {
public:
    void dfs(int child,int par,vector<pair<int,int>>adj[],long long sum,int&cnt,int ss){
        if(sum%ss==0)cnt++;
        for(auto it:adj[child]){
            if(it.first!=par){
                dfs(it.first,child,adj,sum+it.second,cnt,ss);
            }
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1;
        // -><node,wt>
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>count(n,0);
        for(int par=0;par<n;par++){
            vector<int>dist;
            for(auto it:adj[par]){
                int cnt=0;
                dfs(it.first,par,adj,(long long)it.second,cnt,signalSpeed);
                dist.push_back(cnt);
            }
            int sz=dist.size();
            vector<long long >preS(sz+1,0);
            preS[0]=dist[0];
            for(int i=1;i<sz;i++)preS[i]=preS[i-1]+dist[i];

            long long  ans=0;
            for(int i=0;i<sz;i++){
                ans+=(long long)(dist[i]*(preS[sz-1]-preS[i]));
            }
            count[par]=ans;
        }

        return count;
    }
};