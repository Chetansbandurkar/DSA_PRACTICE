class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n=mt.size();
        int m=mt[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // {t,{r,c}};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;

            pq.pop();

            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};

            if(r==n-1 && c==m-1) return t;
            for(int i=0;i<4;i++){
                int nr=drow[i]+r;
                int nc=dcol[i]+c;

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int dst=max(t,mt[nr][nc])+1;
                    if(dist[nr][nc]>dst){
                        dist[nr][nc]=dst;
                        pq.push({dst,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
