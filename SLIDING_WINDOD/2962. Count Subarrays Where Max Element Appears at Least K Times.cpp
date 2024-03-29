
class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        int  mx=-1;
        for(auto it:v){
            mx=max(it,mx);
        }
        int j=0;
        long long ans=0;
        map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
            while(mp[mx]>=k && j<=i){
                ans+=(v.size()-i);
                mp[v[j++]]--;
                // j++;
            } 
        }
        return ans;
    }
};