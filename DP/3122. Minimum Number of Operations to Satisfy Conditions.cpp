class Solution {
public:
vector<vector<int>>dp;
    int solve(int col,int keep,vector<vector<int>>&grid){
        if(col>=grid[0].size()) return 0;
        if(dp[col][keep]!=-1) return dp[col][keep];

        int ans=INT_MAX,cost=0;
        // check for that col if we place the keep value what will be the cost
        for(int row=0;row<grid.size();row++){
            cost+=(grid[row][col]!=keep);
        }
        // then again try to place the next value other than the keep
        //in the nect column
        for(int option=0;option<=9;option++){
            if(option==keep)continue;//agar same value mila to continue kr kyuki
            // hame next col value different chahiye 
            // cost bhi plus kr le 
            ans=min(ans,cost+solve(col+1,option,grid));
        }

        return dp[col][keep]=ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=INT_MAX;
        dp=vector<vector<int>>(m,vector<int>(10,-1));
        for(int keep=0;keep<=9;keep++){
            // col bhej ,konsi value rakhni he vo bhej ,grid
            ans=min(ans,solve(0,keep,grid));
        }
        return ans;
    }
};