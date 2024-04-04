class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax[height.size()];
        leftMax[0]=height[0];
        int mxHt=0;
        int n=height.size();
        for(int i=1;i<n;i++){
            mxHt=max(mxHt,height[i-1]);
            leftMax[i]=mxHt;
        }
        int mxRt=0,ans=0;
        for(int i=n-2;i>=1;i--){
            mxRt=max(mxRt,height[i+1]);
            int curval=min(leftMax[i],mxRt)-height[i];
            if(curval>0){
                ans+=curval;
            }
        }

        return ans;
    }
};