class Solution {
public:
    int n, m;
    void calcPrefSum(vector<vector<int>>& p) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                p[i][j] += p[i][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                p[j][i] += p[j - 1][i];
            }
        }
    }

    int RegionSum(int r1, int c1, int r2, int c2, vector<vector<int>>& psum) {
        int ans = psum[r2][c2];

        if (r1 > 0)
            ans -= psum[r1 - 1][c2];
        if (c1 > 0)
            ans -= psum[r2][c1 - 1];
        if (r1 > 0 && c1 > 0)
            ans += psum[r1 - 1][c1 - 1];

        return ans;
    }

    bool possible(vector<vector<int>>& psum, int k) {

        int minR = INT_MAX;
        int maxR= INT_MIN;
        int maxC = INT_MIN;
        int minC = INT_MAX;
        int cnt = 0;

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {
                int r2 = i + k-1;
                int c2 = j + k-1;

                int sr = RegionSum(i, j, r2, c2, psum);
                if (sr == k * k) {
                    cnt++;
                    maxR = max({maxR, i});
                    minR = min({minR, i});
                    maxC = max({maxC, j});
                    minC = min({minC, j});
                }
            }
        }
        if(cnt<2) return false;
        if (maxR - minR >= k || maxC - minC >= k)
            return true;

        return false;
    }
    int maxArea(vector<vector<int>>& mat) {

        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> psum(n, vector<int>(m));
        psum = mat;
        calcPrefSum(psum);
        int l = 1;
        int h =min(n,m);
        int ans = 0;

        while (l <= h) {
            int mid = (l + h) >> 1;
            if (possible(psum,mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans * ans;
    }
};