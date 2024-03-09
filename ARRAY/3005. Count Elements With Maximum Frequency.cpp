class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int>mp;
       int mx=INT_MIN;
       for(auto it:nums){
           mp[it]++;
           mx=max(mp[it],mx);
       } 
       int cnt=0;
       for(auto it:mp){
           if(it.second==mx){
               cnt+=it.second;
           }
       }
       return cnt;
    }
};