class Solution {
public:
    using ll = long long;

    const ll mod = 1e9 + 7;

    ll binaryExpo(ll a, ll b) {
        ll res = 1;

        a %= mod;

        while (b > 0) {
            if (b & 1) {
                res = (res * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    int countAnagrams(string s) {

        vector<ll> fact(100001);

        fact[0] = 1;

        for (int i = 1; i <= 100000; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        ll res = 1;

        int i = 0;
        int n = s.size();

        while (i < n) {

            map<char, int> mp;

            int cnt = 0;
            while (i < n && s[i] != ' ') {

                mp[s[i]]++;

                cnt++;
                i++;
            }

            ll val = fact[cnt];

            for (auto it : mp) {

                int frequency = it.second;

                val = (val * binaryExpo(fact[frequency], mod - 2)) % mod;
            }

            res = (res * val) % mod;

            i++;
        }

        return res;
    }
};