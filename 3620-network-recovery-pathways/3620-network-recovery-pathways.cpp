class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size() ;
        vector<vector<pair<int,int>>> g(n);
        for (auto it : edges) {
            int x = it[0];
            int y = it[1];
            if(!online[x] || !online[y]) continue;
            g[x].push_back({y,it[2]});
        }

        int  l = 0;
        int h = 1e9;
        int anss = -1;
        while(l<=h){
            int md = (l+h)>>1;

            priority_queue<pair<long long ,int>, vector<pair<long long ,int>>, greater<pair<long long,int>>>pq;
            pq.push({0,0});
            vector<long long>dist(n,LLONG_MAX);
            dist[0]=0;
            bool ans = false;
            while(!pq.empty()){
                auto[w,u]= pq.top();
                pq.pop();
                if(w>k) {
                    break;
                }
                if(w>dist[u]) continue;

                if(u==n-1){
                    ans = true;
                    break;
                }

                for(auto it:g[u]){
                    if(it.second<md) continue;
                    if(dist[it.first]>w+it.second){
                        pq.push({w+it.second,it.first});
                        dist[it.first]=w+it.second;
                    }
                }
            }

            if(ans){
                l=md+1;
                anss = md;
            }else{
                h = md-1;
            }
        }

        return anss ;
    }
};