class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        int n = h.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            int val = min(h[l],h[r])*(r-l);

            ans = max(ans , val);

            if(h[l]<h[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return ans ;
    }
};