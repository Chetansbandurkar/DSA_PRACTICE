class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int sm=nums1[i]+nums2[j];

                if(pq.size()<k){
                    pq.push({sm,{nums1[i],nums2[j]}});
                }
                else if(sm<pq.top().first){
                    pq.pop();// bhula gay bhai ye tu 
                    pq.push({sm,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
            }
        }

        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};