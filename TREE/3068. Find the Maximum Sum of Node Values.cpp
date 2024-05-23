class Solution {
public:
// https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Find%20the%20Maximum%20Sum%20of%20Node%20Values.cpp
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long  sum=0;
        int   min_nuksan=INT_MAX;
        long long  cnt=0;
        for(auto num:nums){
            long long val=num^k;

            if(val>num){
                cnt++;
                sum+=val;
            }
            else{
                sum+=num;
            }
            
            min_nuksan=min((long long)min_nuksan,(long long )abs(num-(num^k)));
        }
        if(cnt%2==0)return sum;

        return sum-min_nuksan;
    }
};



class Solution {
public:
typedef long long ll;
    // https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Find%20the%20Maximum%20Sum%20of%20Node%20Values.cpp
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {

        vector<int> fayda;
        ll normalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            fayda.push_back((nums[i] ^ k) - nums[i]);
            normalSum += 1ll * nums[i];
        }

        sort(fayda.begin(), fayda.end(), greater<int>());

        for (int i = 0; i < fayda.size() - 1; i += 2) {

            ll pairSum = fayda[i] + fayda[i + 1];

            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }
        return normalSum;
        // long long  sum=0;
        // int   min_nuksan=INT_MAX;
        // long long  cnt=0;
        // for(auto num:nums){
        //     long long val=num^k;

        //     if(val>num){
        //         cnt++;
        //         sum+=val;
        //     }
        //     else{
        //         sum+=num;
        //     }

        //     min_nuksan=min((long long)min_nuksan,(long long
        //     )abs(num-(num^k)));
        // }
        // if(cnt%2==0)return sum;

        // return sum-min_nuksan;
    }
};