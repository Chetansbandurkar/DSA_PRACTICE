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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>psum=mat;
        calculatePrefixSum(psum);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int r1=max(0,i-k);
                int c1=max(0,j-k);
                int r2=min((int)mat.size()-1,i+k);
                int c2=min((int)mat[0].size()-1,j+k);
                mat[i][j]=sumRegion(psum,r1,c1,r2,c2);
            }
        }
        return mat;
    }
};