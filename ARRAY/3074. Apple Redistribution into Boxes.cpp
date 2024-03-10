
class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        sort(a.begin(),a.end());
        sort(c.begin(),c.end(),greater<int>());
        int sm=0;
        for(int i=0;i<a.size();i++){
            sm+=a[i];
        }
        int cnt=0;
        for(int i=0;i<c.size();i++){
            sm-=c[i];
            cnt++;
            if(sm<=0)return cnt;
        }
        return cnt;
    }
};