class Solution {
public:
    int findDays(vector<int>&w,int capacity){
        int days=1;
        int curW=0;
        for(auto it:w)
        {
            if(curW+it>capacity){
                days++;
                curW=it;
            }
            else{
                curW+=it;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l=*max_element(w.begin(),w.end());
        int h=accumulate(w.begin(),w.end(),0);
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            int numDays=findDays(w,mid);

            if(numDays<=d){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }

        }

        return ans;
    }
};