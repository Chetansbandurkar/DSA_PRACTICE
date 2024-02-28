class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // transpose the matrix
        // then reverse the  row eaach
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // it also works
        // for(int i=0;i<n;i++){
        //     reverse(mat[i].begin(),mat[i].end());
        // }

        // it also works
        for(int i=0;i<n;i++){
            int l=0; int h=n-1;
            while(l<h){
                swap(mat[i][l++],mat[i][h--]);
            }
        }
    }
};