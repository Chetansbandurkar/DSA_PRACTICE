class Solution
{
public:
    int countBoquets(vector<int> &b_day, int &day, int &k)
    {
        int res = 0;
        for (int i = 0; i < b_day.size(); i++)
        {
            int cnt = 0;
            while (i < (int)b_day.size() && b_day[i] <= day)
            {
                cnt++;
                i++;
            }
            res += (cnt / k);
        }
        return res;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int mx_d = *max_element(bloomDay.begin(), bloomDay.end());
        int start = 1, end = mx_d;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (countBoquets(bloomDay, mid, k) < m)
            {
                start = mid + 1;
            }
            else
            {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};
