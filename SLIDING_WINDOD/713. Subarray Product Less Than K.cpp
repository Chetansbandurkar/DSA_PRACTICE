class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int mul = 1;
        int j = 0;
        for (int i = 0; i < n; i++) {
            mul *= nums[i];
            while (j <= i && mul >= k) {
                mul /= nums[j++];
            }
            ans +=( i - j + 1);
        }

        return ans;
    }
};