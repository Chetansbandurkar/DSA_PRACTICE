class Solution {
public:
    bool judgeSquareSum(int c) {
        // if(c&(c-1)) return 1;

        long long s=0,e=sqrt(c);

        while(s<=e){
            if((s*s+e*e)==c) return 1;

            if((s*s+e*e)>c){
                e=e-1;
            }else{
                s=s+1;
            }
        }

        return 0;
    }
};