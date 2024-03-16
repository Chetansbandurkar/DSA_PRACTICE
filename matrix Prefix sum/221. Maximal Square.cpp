class Solution {
public:
    void calculatePrefixSum(vector<vector<int>>&psum){

        for(int i=0;i<psum.size();i++){
            for(int j=1;j<psum[0].size();j++){
                psum[i][j]+=psum[i][j-1];
            }
        }
        for(int i=0;i<psum[0].size();i++){
            for(int j=1;j<psum.size();j++){
                psum[j][i]+=psum[j-1][i];
            }
        }
    }
    int sumRegion(vector<vector<int>>&psum,int r1,int c1,int r2,int c2){
        int ans=psum[r2][c2];
        if(r1>0)ans-=psum[r1-1][c2];
        if(c1>0)ans-=psum[r2][c1-1];
        if(r1>0 && c1>0)ans+=psum[r1-1][c1-1];
        return ans;
    }
    // calculater is it asquare by usign binary search 
    int calc(vector<vector<int>>&psum,int i,int j){
        int l=1,r=min(psum.size()-i,psum[0].size()-j);
        // binary search
        int ans=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int bot_x=i+mid-1;// botom row;
            int bot_y=j+mid-1;//col ceck at left;
            if(sumRegion(psum,i,j,bot_x,bot_y)==mid*mid){
                ans=mid*mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& mat) {
        vector<vector<int>>psum(mat.size(),vector<int>(mat[0].size()));
        // can't copy directly as it will copy string 1 and 0(char0)
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                psum[i][j]=mat[i][j]-'0';
            }
        }
        calculatePrefixSum(psum);
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='1'){
                    // checking for 1 as 0 cnat form the square
                   ans=max(ans, calc(psum,i,j));
                }
            }
        }
        return ans;
    }
};