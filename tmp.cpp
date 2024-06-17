class Solution
{
public:
    long long solve(vector<int> &p, int ind, long long rew,map<long long ,long>&mp)
    {
        if (ind >= p.size())
            return 0;

        if (dp[ind]!= -1)
            return dp[ind][prev + 1];
        long long inc = 0, exc = 0;
        if (prev == -1 || !mp[p[ind]+1] && !mp[p[ind]-1 && !mp[p[ind]-2]] && !mp[p[ind]+2])
        {
            mp[p[ind]]++;
            inc = p[ind] + solve(p, ind + 1, rew + p[ind]);
            mp[p[ind]]--;
        }
        exc = solve(p, ind + 1, rew);

        return dp[ind] = max(inc, exc);
    }
    long long maximumTotalDamage(vector<int> &power)
    {
    }
};