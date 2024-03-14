class Solution {
public:
    int pivotInteger(int n) {
        int sm=0;
        if(n==1)return 1;
        for(int i=1;i<=n;i++)sm+=i;
       // int sm=n*(n+1)/2;
        int val=0;
        for(int i=1;i<=n;i++){
            val+=i;
            sm-=i;
            if(val>sm)return -1;
            if(sm-(i+1)==val)return i+1;
        }

        return -1;
    }
};

class Solution {
public:
    int pivotInteger(int n) {
        int sm=n*(n+1)/2;
        if(n==1)return 1;
        int val=0;
        for(int i=1;i<=n;i++){
            val+=i;
            sm-=i;
            if(val>sm)return -1;
            if(sm-(i+1)==val)return i+1;
        }
        return -1;
    }
};