class Solution {
public:
    
    // int dp[100005][100005][100005];
    // int solve(int late,int abs,int pre,int n ){
    //     if(n==0 ||n<=0) return 1;
    //     // if(dp[late][abs][pre][n]!=-1) return dp[late][abs][pre][n];
    //     int l=(late<2)?solve(late+1,abs,pre,n-1):0;
    //     int a=(abs<1)?solve(late,abs+1,pre,n-1):0;
    //     int p=solve(late,abs,pre+1,n-1);

    //     return l+a+p;
    // }
    using ll = long long;
    const long long mod=1e9+7;
    long long dp[100001][5][5];

    // the mistake i made in above and below code idsthat 
    // we don't want the three cons ..late so in every present and abset we have to send
    // the late as 0;
    ll solve(ll late,ll abs,ll n ){
        if(n==0) return 1;
        if(dp[n][abs][late]!=-1) return dp[n][abs][late];
        ll ans=(late<2?solve(late+1,abs,n-1):0);//L
        ans+=(abs<1?solve(0,abs+1,n-1):0);//A
        ans+=solve(0,abs,n-1);//P

        return dp[n][abs][late]=(ans)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n);
    }
};