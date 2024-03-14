class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>res;
        // how many diagonal can we have 
        for(int d=0;d<n+m-1;d++){
            int st=res.size();
            
            int r=d<m?0:d-m+1;
            int c=d<m?d:m-1;

            while(r<n && c>=0){
                res.push_back(mat[r][c]);
                r++;
                c--;
            }

            if(d%2==0){
                reverse(res.begin()+st,res.end());
            }

        }

        return res;
    }
};