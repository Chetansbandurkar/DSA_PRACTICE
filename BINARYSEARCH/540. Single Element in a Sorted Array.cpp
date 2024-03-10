
class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int i=0,j=a.size()-1;
        if(a.size()==1)return a[0];
        if(a[0]!=a[1])return a[0];
        while(i<=j){
            int md=(i+j)/2;
            cout<<md<<" ";
            if(md%2==1){
                if(a[md]==a[md-1] && md>=1){
                    i=md+1;
                }
                else if(a[md]==a[md+1] && md<a.size()){
                    j=md-1;
                }
                else{
                    return a[md];
                }
            }
            else{
                if(a[md]==a[md+1] && md<a.size()-1){
                    i=md+1;
                }else if(a[md]==a[md-1] && md-1>=0){
                    j=md-1;
                }
                else return a[md];
            }
        }

        return 0;
    }
};