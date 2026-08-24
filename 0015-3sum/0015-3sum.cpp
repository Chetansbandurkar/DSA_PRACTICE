class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int j = i + 1, k = n - 1;

            while (j < k) {
                int val = nums[i] + nums[j] + nums[k];

                if (val == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                } else if (val < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }
};