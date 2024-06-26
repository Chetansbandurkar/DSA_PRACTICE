class Solution {
public:
    vector<int> z_function(string&s){
        int n=s.size();
        vector<int>z(s.size(),0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<r){
                z[i]=min(r-i,z[i-l]);
            }

            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }

            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        return z;
    }
    string longestPrefix(string s) {
        string zString = s + "#" + s;
        vector<int>z=z_function(zString);
        for(int i=s.size()+2;i<z.size();i++){
            if(z[i] == z.size()-i) return s.substr(i-s.size()-1,z[i]);
        }
        return "";
    }
};