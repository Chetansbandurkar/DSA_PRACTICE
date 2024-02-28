class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>>adj[n];
        for(auto it:meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // You Can tell secret to other only when the
        // time of meeting freter than or equlas to your pre time
        queue<pair<int,int>>q;
        // <Node,Time>
        vector<int>vis(n+1,INT_MAX);
        q.push({0,0});
        q.push({firstPerson,0});
         vis[0]=0;;
         vis[firstPerson]=0;
        while(!q.empty()){
            auto it =q.front();q.pop();
            int node=it.first;
            int time=it.second;
            for(auto itr:adj[node])
            {
                int adjNode=itr.first;
                int t=itr.second;
                if(t>=time && vis[adjNode]>t){
                    vis[adjNode]=t;
                    q.push({adjNode,t});
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};