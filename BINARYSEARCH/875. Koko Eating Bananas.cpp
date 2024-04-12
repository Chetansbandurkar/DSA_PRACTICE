class Solution {
public:
    long long  calHr(vector<int>& piles, int h) {
        long long  total=0;
        for(int i=0;i<piles.size();i++){
            total+=(piles[i]+h-1)/h;

        }

        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int  mx = 0;
        // maximum value that cna be the  ans
        for (int i = 0; i < piles.size(); i++) {
            mx = max(piles[i], mx);
        }

        long long  l = 1, r = mx;
        while (l <= r) {
            long long  mid = l + (r - l) / 2;
            long long  totHr=calHr(piles,mid);
            if(totHr<=h){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};