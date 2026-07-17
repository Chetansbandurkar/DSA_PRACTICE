class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n=mt.size();
        int m =mt[0].size();
        // {time,r,c, 1 or 2 to be added};
        priority_queue<tuple<int,int, int,bool>,vector<tuple<int,int,int,bool>>,greater<tuple<int,int,int,bool>>>pq;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        pq.push({0,0,0,true});
        while(!pq.empty()){
            auto [time,r,c,check]=pq.top();
            pq.pop();
            if(r==n-1 && c==m-1) return time;

            int newT=check?1:2;
            for(int i=0;i<4;i++){
                int nr=drow[i]+r;
                int nc=dcol[i]+c;
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int dst=max(time,mt[nr][nc])+newT;

                    if(dst<dist[nr][nc]){
                        dist[nr][nc]=dst;
                        pq.push({dst,nr,nc,!check});
                    }
                }
            }
        }

        return -1;
    }
};