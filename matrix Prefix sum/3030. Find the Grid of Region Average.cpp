class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0)),
            count(n, vector<int>(m, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int sum = 0;
                bool isRegion = true;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        sum += image[k][l];
                        // check for the upper side and the back side only u
                        // will get the sum region do dry run
                        if (k > i &&
                            abs(image[k][l] - image[k - 1][l]) > threshold)
                            isRegion = false;
                        if (l > j &&
                            abs(image[k][l] - image[k][l - 1]) > threshold)
                            isRegion = false;
                    }
                }
                sum /= 9;
                if (isRegion) {
                    for (int k = i; k < i + 3; k++) {
                        for (int l = j; l < j + 3; l++) {
                            count[k][l]++;
                            res[k][l]+=sum;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(count[i][j]==0){
                    res[i][j]=image[i][j];
                }
                else{
                    res[i][j]/=count[i][j];
                }
            }
        }

        return res;
    }
};