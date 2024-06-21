class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int ans=0;
        int n=c.size();
        for(int i=0;i<n;i++){
            if(g[i]==0){
                ans+=c[i];
            }
        }
        int unsats=0;
        for(int i=0;i<m;i++){
            if(g[i]==1){
                unsats+=c[i];
            }
        }

        int mx=unsats;

        for(int i=m;i<n;i++){
            if(g[i-m]==1){
                unsats-=c[i-m];
            }
            if(g[i]==1){
                unsats+=c[i];
            }
            mx=max(mx,unsats);
        }

        return ans+mx;
    }
};