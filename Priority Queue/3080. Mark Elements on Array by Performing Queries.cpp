class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        map<int,bool>vis;
        long long  sm=0;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            sm+=nums[i];
        }
        vector<long long >ans;
        for(auto it:queries){
            int ind=it[0];
            int k=it[1];
            if(!vis[ind])
            sm-=nums[ind];
            vis[ind]=1;
            while(k && !pq.empty()){
                auto f=pq.top();pq.pop();
                int val=f.first;
                int ind=f.second;
                if(!vis[ind]){
                    sm-=nums[ind];
                    k--;
                    vis[ind]=1;
                }
                
            }
            ans.push_back(sm);
        }
        return ans;
        
    }
};