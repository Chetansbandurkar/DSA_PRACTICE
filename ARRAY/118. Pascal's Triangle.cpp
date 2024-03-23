class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        ans.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int>tmp(i+1,0);
            for(int j=0;j<=i;j++){
                if(j==0|| j==i){
                    tmp[j]=1;
                }
                else
                {
                    tmp[j]=ans[i-1][j]+ans[i-1][j-1];
                }
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};