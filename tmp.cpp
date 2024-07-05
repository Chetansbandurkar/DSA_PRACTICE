class Solution
{
public:
    int solve(vector<int> &nums, int ind, int prev, vector<int> v, int &k)
    {
        if (ind >= nums.size())
            return 0;
        int ans = 0;
        if (prev == -1 || (!v.empty()) && (nums[ind] + nums[prev]) % k == v.back())
        {
            v.push_back(nums[ind]);
            ans = 1 + solve(nums, ind + 1, ind, v, k);
            v.pop_back();
        }
        int exc = solve(nums, ind + 1, prev, v, k);

        return max(exc, ans);
    }
    int maximumLength(vector<int> &nums, int k)
    {
        vector<int> v;
        return solve(nums, 0, -1, v, k)
    }
};