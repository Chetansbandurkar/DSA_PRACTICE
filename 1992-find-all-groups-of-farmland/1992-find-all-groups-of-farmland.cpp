class Solution {
public:
    void solve(int i, int j, int &r2, int &c2, vector<vector<int>>&l )
    {
        if(i>=l.size() || j>=l[0].size() || i<0 || j<0 ||  l[i][j]==0) return ;

        r2 = max(r2,i);
        c2= max(c2,j);
        l[i][j]=0;
        solve(i+1,j,r2,c2,l);
        solve(i,j+1,r2,c2,l);
        solve(i,j-1,r2,c2,l);
        solve(i-1,j,r2,c2,l);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& l) {
        int n = l.size();
        int m = l[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(l[i][j]==1){
                    int r1 = i;
                    int r2 = i;
                    int c1 = j;
                    int c2=j;

                    solve(i,j,r2,c2,l);
                    ans.push_back({r1,c1,r2,c2});
                }
            }
        }

        return ans ;
    }
};