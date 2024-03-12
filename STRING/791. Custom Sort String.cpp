class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i])!=mp.end()){
                ans+=string(mp[order[i]],order[i]);
                mp.erase(order[i]);
            }
        }

        if(!mp.empty()){
            for(auto it:mp){
                ans+=string(it.second,it.first);
            }
        }

        return ans;
    }
};