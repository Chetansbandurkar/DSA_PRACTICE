class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string ,int>mp;
        for(auto it : words){
            mp[it]++;
        }

        int cnt  = 0;
        int n = s.size();
        for(auto it:mp){
            int i = 0; int j = 0;

            string ss = it.first;
            int m = ss.size();
            while(i<n && j<m ){
                if(s[i]==ss[j]){
                    i++;
                    j++;
                }
                else i++;
            }

            if(j==ss.size()) cnt+=it.second;
        }

        return cnt ;
    }
};