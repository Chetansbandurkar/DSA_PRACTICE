class Solution {
public:
    int ans=-1;
    void solve(vector<int>&nums,int &k,unordered_map<int,int>&mp,int ind){
        if(ind==nums.size()){
            ans++;
            return ;
        }
        // non take
        solve(nums,k,mp,ind+1);
        // check kr for diff ki ham le sakte ki nhi 

        if(!mp[nums[ind]-k] && !mp[nums[ind]+k]){
            mp[nums[ind]]++;
            solve(nums,k,mp,ind+1);
            mp[nums[ind]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        solve(nums,k,mp,0);
        // bha
        return ans;
    }
};