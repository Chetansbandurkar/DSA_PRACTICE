class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    //    int prev=-1;
       int i=0;
       int n=points.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       for(auto it:points){
        pq.push({it[0],it[1]});
       }
       auto f=pq.top();pq.pop();
       int prev=f.second;
       int cnt=1;
       while(!pq.empty()){
        auto it=pq.top();pq.pop();
        int xs=it.first;
        int xe=it.second;
        if(xs<=prev){
            prev=min(prev,xe);
        }else{
            cnt++;
            prev=xe;
        }
       }
       return cnt;
    }
};