class Solution {
public:
    int minBitFlips(int s, int g) {
        int cnt=0;
        for(int i=0;i<31;i++){
            if(s&(1<<i) && g&(1<<i) || !(s&(1<<i) )&& !(g&(1<<i)) ){
                continue;
            }
            else cnt++;
        }

        return cnt;
    }
};