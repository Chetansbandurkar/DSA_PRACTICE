class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        st.push(n-1);
        // vector<int>res(n);
        map<int,int>res;
        res[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                st.pop();
            }
            res[nums2[i]]=(!st.empty())?nums2[st.top()]:-1;
            st.push(i);
        }

        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=res[nums1[i]];
        }
        return ans;
    }
};