class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // <node, time>
        adj[0].push_back({firstPerson , 0});
        adj[firstPerson].push_back({0 , 0});

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,0});
        pq.push({0, firstPerson});
        // <time , node>
        vector<int>dis(n,INT_MAX);

        vector<int>list;

        while(!pq.empty()){
            auto it = pq.top();

            pq.pop();

            int t = it.first;
            int u = it.second;

            if(dis[u]!=INT_MAX) continue;
            dis[u]=t;
            list.push_back(u);

            for(auto [v,tm] : adj[u])
            {
                if(dis[v]!=INT_MAX || t>tm) continue;

                pq.push({tm,v});
            }

        }

        return list;
    }
};