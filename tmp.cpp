class Solution
{
public:
    string getSmallestString(string s, int k)
    {

        map<int, char> map;

        for (int i = 1; i <= 26; ++i)
        {
            map[i] = 'a' + i;
        }
        for (int i = 0; i < s.size() && k; i++)
        {
            int val = s[i] - 'a'+1;
            cout << val << endl;
            int m = val + k;
            int kv = 26 - val + 1;
            // k-=kv;
            if (m > 26 && kv < val)
            {
                s[i] = map[kv];
                k -= kv;
            }
            else if (k <= val)
            {
                if (k == val)
                    s[i] = map[val - k];
                k;
            }
            else
            {
                s[i] = map[0];
                k -= val;
            }
        }
        return s;
    }
};