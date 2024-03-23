class Solution {
public:
    int maxArea(vector<int>& ht) {
        int l=0,r=ht.size()-1;
        int ans=0;
        while(l<r){
            int ar=(min(ht[l],ht[r]))*(r-l);
            ans=max(ar,ans);
            if(ht[l]<ht[r]){
                l++;
            }else{
                r--;
            }
        }

        return ans;
    }
};