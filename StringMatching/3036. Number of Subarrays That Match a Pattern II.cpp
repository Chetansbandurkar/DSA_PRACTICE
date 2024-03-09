class Solution {
public:
    vector<int> z_function(string s) {
        int n = (int)s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        z[0] = s.size();
        return z;
    }
    int countMatchingSubarrays(vector<int>& a, vector<int>&b) {
        string b1;
        string tmp;
        for(int i=0;i<b.size();i++){
            if(b[i]==1){
                tmp.push_back('a');
            }
            else if(b[i]==0){
                tmp.push_back('b');
            }
            else tmp.push_back('c');
        }
        for(int i=0;i<a.size()-1;i++){
            if(a[i+1]>a[i]){
                b1.push_back('a');
            }
            else if(a[i+1]==a[i]){
                b1.push_back('b');
            }else{
                b1.push_back('c');
            }
        }

        vector<int>zf=z_function(tmp+b1);
        int ans=0;
        for(int i=tmp.size();i<(tmp.size())+(b1.size());i++){
            if(zf[i]>=tmp.size()){
                ans++;
            }
        }
        return ans;
    }
};