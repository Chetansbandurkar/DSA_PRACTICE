class Solution {
public:
// sliding window 
    string minWindow(string s, string t) {
        int n=s.size();
        // map me store kr;
        map<int,int>mp;
        for(char &ch:t){
            mp[ch]++;
        }
        int i=0,j=0;
        int right_window_side=INT_MAX;//->
        int left_window_side=0;//<-
        int require=t.size();
        while(j<n){
            char ch_j=s[j];
            if(mp[ch_j]>0)require--;
            // also think for the test case
            // AAAA+ADOBES....(give 1st example) for bellow case if T=ABC
            mp[ch_j]--;// agar t me present nhi he to less than 0 ho jayege 
            while(require==0){
                char ch_i=s[i];
                if(right_window_side>j-i+1){
                    right_window_side=j-i+1;
                    left_window_side=i;
                }
                mp[ch_i]++;
                //matlab require ki value badh gayi or ek valu chahiye age ke index se
                // i++
                if(mp[ch_i]>0){
                    require++;
                }
                i++;
            }
            j++;
        }
        return right_window_side==INT_MAX? "":s.substr(left_window_side,right_window_side);
    }
};