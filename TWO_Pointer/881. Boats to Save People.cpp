class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        int cnt=0;
        int n=p.size();
        int i=0,j=n-1;
        sort(p.begin(),p.end());
        while(i<=j){
            cnt++;
            if(p[i]+p[j]<=l){
                i++;
                j--;
            }
           else  if(p[i]+p[j]>l){
                j--;
            }
            else{
                i++;
            }
        }

        return cnt;
    }
};