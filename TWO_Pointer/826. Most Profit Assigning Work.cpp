class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& pr, vector<int>& w) {
        int ans=0;
        vector<pair<int,int>>p;
        for(int i=0;i<pr.size();i++){
            p.push_back({d[i],pr[i]});
        }
        sort(w.begin(),w.end());
        sort(p.begin(),p.end());
        int mxP=0;
        int tp=0;
        for(int i=0,j=0;i<w.size();i++){
            // int a=0,b=0;
            while(j<w.size() && p[j].first<=w[i]){
                tp=max(p[j].second,tp);
                j++;
            }

            if(j>0 && p[j-1].first<=w[i]){
                ans+=tp;
            }

        }

        return ans;
    }
};