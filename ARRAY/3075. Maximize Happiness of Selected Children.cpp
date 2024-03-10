class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans=0;
        long long cnt=0;
        sort(h.begin(),h.end(),greater<int>());
        for(int i=0;i<h.size() && k>0;i++){
            h[i]-=cnt;
            if(h[i]>=0)
            ans+=h[i];
            k--;
            cnt++;
        }
        return ans;
    }
};