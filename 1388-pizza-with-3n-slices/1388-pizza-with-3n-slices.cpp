class Solution {
public:
    vector<vector<int>>dp;
    int solve(int ind,int rem ,int & n,vector<int>&s){
        if(rem<=0 || ind>=n) return 0;
        if(dp[ind][rem]!=-1) return dp[ind][rem];
        int take = s[ind]+solve(ind+2,rem-1,n,s);
        int nTake = solve(ind+1,rem,n,s);

        return dp[ind][rem]=max(take, nTake);
    }
    int maxSizeSlices(vector<int>& s) {
        int n = s.size();
        int k = n/3;
        dp.assign(n, vector<int>(k+1,-1));
        n--;
        int ans1 = solve(0,k,n,s);
        n++;
        dp.assign(n, vector<int>(k+1,-1));
        int ans2= solve(1,k,n,s);

        return max(ans1, ans2);
    }
};