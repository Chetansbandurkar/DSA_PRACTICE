class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) {
        vector<vector<int>>ans;

        sort(inv.begin(),inv.end());

        if(inv.size()<=0) return ans;
        int n= inv.size();

        int l = inv[0][0];
        int r = inv[0][1];

        for(int i=1;i<n;i++){

            if(inv[i][0]>r){
                ans.push_back({l,r});
                l = inv[i][0];
                r = inv[i][1];
            }
            else{
                l = min(inv[i][0],l);
                r = max(inv[i][1],r);
            }
        }

        ans.push_back({l,r});

        return ans ;
    }
};