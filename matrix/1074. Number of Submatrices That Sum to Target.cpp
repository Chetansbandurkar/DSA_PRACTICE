class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
        int row=m.size();
        int col=m[0].size();
        for(int r=0;r<row;r++){
            // c->1;? abe pref sum nikal raha he tu 
            for(int c=1;c<col;c++){
                m[r][c]+=m[r][c-1];
            }
        }
        int res=0;
        // fixed the col
        for(int startCol=0;startCol<col;startCol++){
            // till that column ,to be checked
            for(int curCol=startCol;curCol<col;curCol++){
                // need to find all sub matrrix;
                // now come the concept of "no of subarr with sum k (560LC)";
                unordered_map<int,int>mp;
                // always hav to store sum=0 
                mp[0]=1;
                int sum=0;
                // go down by check each subm matrix of startcol to cur_col
                // and till row 
                for(int r=0;r<row;r++){
                    sum+=m[r][curCol]-(startCol>0?m[r][startCol-1]:0);
                    if(mp.count(sum-target)){
                        res+=(mp[sum-target]);
                    }
                    mp[sum]++;
                }
            }
        }

        return res;
    }
};