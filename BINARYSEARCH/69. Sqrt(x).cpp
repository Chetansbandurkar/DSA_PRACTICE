class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        long long l=1;
        long long h=x;
        long long ans=0;
        while(l<=h){
            long long  md=l+(h-l)/2;
            long long val=md*md;
            if(val==x)return md;
            if(val>x){
                h=md-1;
            }else{
                ans=md;
                l=md+1;
            }
        }

        return ans;
    }
};