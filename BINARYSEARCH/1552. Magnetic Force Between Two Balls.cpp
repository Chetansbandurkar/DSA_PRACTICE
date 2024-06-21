class Solution {
public:
    bool canPlace(vector<int>&p,int &df ,int&m){
        int lst=p[0];
        int cnt=1;
        for(int i=1;i<p.size();i++){

            if(p[i]-lst>=df){
                lst=p[i];
                cnt++;
            }

            if(cnt>=m)  return 1;
        }

        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        int lo=1;
        int hi=1e9;
        int ans=1;
        sort(position.begin(),position.end());
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(canPlace(position,mid,m)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }


        return ans;
    }
};