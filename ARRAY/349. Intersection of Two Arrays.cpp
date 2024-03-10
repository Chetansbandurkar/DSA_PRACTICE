class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        int i=0,j=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                if(!ans.empty() && ans.back()==a[i])
                {
                    i++;
                    j++;
                    continue;
                }
                else ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else i++;
        }

        return ans;
    }
};