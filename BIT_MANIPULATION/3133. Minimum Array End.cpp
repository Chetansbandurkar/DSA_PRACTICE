class Solution {
public:
    long long minEnd(int n, int x) {
        // think for the x=1e8  it will have the valuw of 2^62
        // so lopp will run for 63
        // ->APPROACH
        //   1> keep the value of unset index in x;
        //conside example
        // n=5,4)x=5
        // number till 5th n
        // 101,111,1101,1111,10101
        vector<long long >v;
        long long ans=0;
        for(int i=0;i<64;i++){
            if(!(x&(1LL<<i))){
                v.push_back(i);
            }
        }
        n--;
        for(int i=0;i<64;i++){
            if(n&(1L<<i)){
                ans+=(1LL<<v[i]);
            }
        }
        ans+=x;

        return ans;
    }
};