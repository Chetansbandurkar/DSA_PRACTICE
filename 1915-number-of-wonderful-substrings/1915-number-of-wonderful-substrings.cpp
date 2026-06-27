class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long mask = 0;
        vector<int>count(1024,0);
        count[0]=1;
        long long  ans = 0;
        for(auto s : word){
            mask ^= 1<<(s-'a');
            for(int i=0;i<10;i++){
                ans+=count[mask^(1<<i)];
            }
            ans+=count[mask];

            count[mask]++;
        }

        return ans ;
    }
};