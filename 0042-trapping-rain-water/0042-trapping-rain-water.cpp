class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> lMax(n);
        lMax[0] = h[0];
        for (int i = 1; i < n; i++) {
            lMax[i] = max(h[i], lMax[i - 1]);
        }
        int rMax = h[n - 1];
        int ans = 0;

        for(int i=n-2;i>0;i--){
            rMax =max(rMax,h[i]);
            int val = min(rMax, lMax[i]);
            int cal = val-h[i];
            if(cal>0){
                ans += cal;
            }
        }
        return ans ;
    }
};