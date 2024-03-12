class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        if(n ==1)return 0;
       if(a[n-1]>a[n-2])return n-1;
       if(a[0]>a[1])return 0;
       int l=1;
       int h=n-2;
       while(l<=h){
           int md=(l+h)/2;
           if(a[md]>=a[md-1] && a[md]>=a[md+1]){
               return md;
           }
           else if(a[md]>a[md-1]){
               l=md+1;
           }else{
               h=md-1;
           }
       }
       
       return -1;
    }
};