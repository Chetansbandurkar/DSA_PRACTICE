class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0;
        int h=a.size()-1;
        int n=a.size();
        if(n==1){
            if(a[0]==target)return 0;
            else return -1;
        }
        if(n==2){
            if(a[0]==target)return 0;
            if(a[1]==target)return 1;
            return -1;
        }
        while(l<=h){
            int md=(l+h)/2;

            if(target==a[md])return md;
            if(a[md]>=a[l] && a[md]>a[h]){
                if(target<=a[md] && target>=a[l]){
                    h=md-1;
                }else l=md+1;
            }
            else{
                if(target>a[md] && target>a[h]){
                    h=md-1;
                }else  if(target<a[md] && target<a[l]){
                    h=md-1; 
                }else if(target<a[md]){
                    h=md-1;
                }else l=md+1;
            }
        }

        return -1;
    }
};

