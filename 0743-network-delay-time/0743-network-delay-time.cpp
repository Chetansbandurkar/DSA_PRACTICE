class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int,int>>st;
        // st.insert({0,k});

        vector<int>dist(n+1, INT_MAX);
        vector<vector<pair<int,int>>>g(n+1);
        for(auto it:times){
            g[it[0]].push_back({it[1],it[2]});
        }
        st.insert({0,k});
        dist[k] = 0;
        while(!st.empty()){
            pair<int,int> p = *st.begin();
            st.erase(st.begin());
            if(p.first>dist[p.second])continue;

            for(auto node : g[p.second]){

                if(node.second + p.first<dist[node.first]){
                    dist[node.first] = node.second + p.first;
                    st.insert({dist[node.first],node.first});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,dist[i]);
        }

        if(ans==INT_MAX) return -1;
        return ans ;
    }
};