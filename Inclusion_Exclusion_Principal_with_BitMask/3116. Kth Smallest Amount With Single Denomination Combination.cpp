class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // inclusion exclusion algorith coding blocks
        long long low = 0, high = 1e18;
        int n = coins.size();
        long long ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            //    total values including all values
            long long c = 0;
            //    how many subset can be form with bits n(length of the arrya)
            for (int j = 1; j < (1 << n); j++) {
                long long lcm = 0, x = 0;
                for (int i = 0; i < n; i++) {
                    if (j & (1 << i)) {
                        x++; // cnt set bit
                        if (lcm == 0) {
                            lcm = coins[i];
                        } else {
                            lcm = lcm * 1ll * coins[i] /
                                  __gcd(lcm, 1ll * coins[i]);
                        }
                    }
                }
                if (x % 2) {
                    c += mid / lcm;
                } else {
                    c -= mid / lcm;
                }
            }

            if (c >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};