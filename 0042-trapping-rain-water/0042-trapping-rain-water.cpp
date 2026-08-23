class Solution {
public:
    int trap(vector<int>& h) {
        vector<int>left(h.size());
        left[0]=h[0];
        int mx_ht=0;
        for(int i=1;i<h.size();i++){
            mx_ht=max(mx_ht,h[i-1]);
            left[i]=mx_ht;
        }

        int rt_mx=0;
        int ans=0;
        for(int i=h.size()-2;i>=1;i--){
            rt_mx=max(rt_mx,h[i+1]);
            int cur_val=min(left[i],rt_mx)-h[i];
            if(cur_val>0){
                ans+=cur_val;
            }
        }

        return ans;
    }
};