class Solution {
public:
    vector<vector<int>>dp;
    int solve(int r,int Prevc,vector<vector<int>>&grid){
        if(r>=grid.size())  return 0;
        if(dp[r][Prevc]!=-1) return dp[r][Prevc];
        int ans=1e5;
        for(int i=0;i<grid[0].size();i++){
            if(Prevc!=i){
                ans=min(ans,grid[r][i]+solve(r+1,i,grid));
            }
        }
        return dp[r][Prevc]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=1e5;
        if(grid.size()== 1&& grid[0].size()==1) return grid[0][0];
        dp=vector<vector<int>>(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        for (int j = 0; j < grid[0].size(); j++) {
            ans = min(ans, solve(0,j,grid));
        }
        return ans;
    }
};