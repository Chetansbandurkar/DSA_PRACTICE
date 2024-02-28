class Solution {
public:
    int numberOfSubstrings(string s) {
       int hash[3]={0};
       int i=0,j=0,ans=0;
       while(j<s.size()){
           hash[s[j]-'a']++;
           while(hash[0] && hash[1] && hash[2]){
               ans+=(s.size()-j);
               hash[s[i]-'a']--;
               i++;
           }
           j++;
       }
       return ans;
    }
};