class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] %= k;
        }

        int j = 0;
        int ans = 0;
        int cur = nums[0];
        int val = 0;
        for (int i = 0; i < n; i++) {
            val += nums[i];
            while (nums[j] != nums[i]) {
                val -= nums[j];
                j++;
            }
            cur = nums[i];
            if (val % k == cur)
                ans = max(ans, i - j + 1);
        }

        return ans;
    }
};