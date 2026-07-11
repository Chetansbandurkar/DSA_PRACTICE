struct Edge
{
    int v;
    int s;
    int e ;
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& ed) {
        vector<vector<Edge>> g(n);
        for (auto it : ed) {
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int e = it[3];
            g[u].push_back({v, s, e});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n, INT_MAX);
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int u = node.second;
            int tm = node.first;

            if (tm > dist[u])
                continue;

            for (auto it : g[u]) {
                int v = it.v;
                int s = it.s;
                int e = it.e;
                int reqTime = 0;
                if(tm>=s && tm<=e)
                {
                    reqTime = tm+1;
                }
                else if(tm>e) continue;
                else if(tm<s) reqTime=(s-tm+1)+tm;

                if(dist[v]>reqTime){
                    pq.push({reqTime, v});
                    dist[v]=reqTime;
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};