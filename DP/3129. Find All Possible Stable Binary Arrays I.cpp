class Solution {
public:
    int dp[205][205][2];
    int mod=1e9+7;
    int solve(int zero,int one,int&limit,bool ms){
        if(one==0 && zero==0) return 1;
        // ms -> u have include or not 
        if(dp[zero][one][ms]!=-1) return dp[zero][one][ms];
        int ans=0;
        if(ms==false){// prev i have taken  1
            for(int i=1;i<=min(zero,limit);i++){
                ans= (ans+solve(zero-i,one,limit,true)%mod)%mod;
            }
        }
        else if(ms==true){// prev i have taken 0
            for(int i=1;i<=min(one,limit);i++){
                ans=(ans+solve(zero,one-i,limit,false)%mod)%mod;
            }
        }
        return dp[zero][one][ms]=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int a=solve(zero,one,limit,false)%mod;
        int b=solve(zero,one,limit,true)%mod;
        return (a+b)%mod;
    }
};