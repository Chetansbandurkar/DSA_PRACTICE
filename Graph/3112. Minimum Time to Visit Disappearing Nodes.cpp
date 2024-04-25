class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
         vector<pair<int, int>> a[n];
        for (auto it : edges) {
            a[it[0]].push_back({it[1], it[2]});
            a[it[1]].push_back({it[0], it[2]});
        }
        long long INF=1e9;
        vector<int>d(n,INF);
        set<pair<long long,long long>>q;
        q.insert({0,0});
        d[0]=0;
        while(!q.empty()){
            int v=q.begin()->second;
            int time=q.begin()->first;
            q.erase(q.begin());
            for(auto it:a[v]){
                int adjNode=it.first;
                int timeTak=it.second;
                if((time+timeTak<d[adjNode]) && (time+timeTak<disappear[adjNode])){
                    q.erase({d[adjNode],adjNode});
                    d[adjNode]=time+timeTak;
                    q.insert({d[adjNode],adjNode});
                }
            }
        }

        for (int i=0;i<d.size();i++){
            if (d[i]==INF){
                d[i]=-1;
            }
        }
        return d;
    }
};




// WITH MIN HEAP PQ
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {
        vector<pair<int, int>> a[n];
        for (auto it : edges) {
            a[it[0]].push_back({it[1], it[2]});
            a[it[1]].push_back({it[0], it[2]});
        }
        vector<int> res(n, 1e5);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        res[0] = 0;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            int node = top.second;
            int time = top.first;
            pq.pop();
            if(time!=res[node]) continue;

            for (auto it : a[node]) {
                int adjNode = it.first;
                int timeTak = it.second;

                if (timeTak + time < res[adjNode] &&
                    timeTak + time < disappear[adjNode]) {
                    res[adjNode] = timeTak + time;
                    pq.push({timeTak + time, adjNode});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (res[i] == 1e5) {
                res[i] = -1;
            }
        }

        return res;
    }
};