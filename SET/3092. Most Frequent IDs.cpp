class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        set<pair<long long , int>> st;
        map<int, long long> mp;
        for (int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i])!=mp.end()){
                long long val=mp[nums[i]];
                st.erase({val,nums[i]});
            }
            mp[nums[i]]+=freq[i];
            if(mp[nums[i]]==0){
                mp.erase(mp[nums[i]]);
            }else{
                st.insert({mp[nums[i]],nums[i]});
            }

            if(st.empty()){
                ans.push_back(0);
            }else{
                auto it=st.end();
                it--;
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};