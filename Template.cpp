#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define MAXN 1000001
//    mn=*min_element(ans.begin(),ans.end());
//    cout<<min_element(ans.begin(),ans.end())-ans.begin()+1<<endl;
int gcd (int a, int b) {  
	if (b == 0) return a;
	return gcd (b, a % b);
}
// to clculate the value in string form such as 12345 ->convert in num not a string
int fun(string s)
{
    int n = s.size();a
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}
int mex(vector<int>&a)
{
    int  n=a.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(int i=0;i<=n;i++){
        if(mp[i]==0){
            return i;
        }
    }

    return n+1;
}
int mod=1e9+7;
// modulo multiplicative inverse
 long long mpow(long long x,long long y){
    long long p=1;
    while(y>0){
        // ans = (ans*mpow(2,mod-2))%mod;
        if(y&1){>
            p=(p*x)%mod;
        }
        x=(x*x)%mod;
        y>>=1;
    }
    return p;
 }
// to check is it a Prime no or not
vector<int> primeFactors(int n)
{
   vector<int> temp;

   while (n % 2 == 0)
   {
      temp.push_back(2);
      n = n / 2;
   }

   for (int i = 3; i <= sqrt(n); i = i + 2)
   {

      while (n % i == 0)
      {
         temp.push_back(i);
         n = n / i;
      }
   }

   if (n > 2)
      temp.push_back(n);
   return temp;
}
bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
vector<int> spf(MAXN, 0);
map<int, int> factors;
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
// To find the power of a^b
// recursive bt iterative is less complex
int binExpRecc(int a,int b){
    if(b==0)return 1;
    int res=binExpRecc(a,b/2);
    if(b&1){
        return (a*(res*1LL * res));// mode bhi kr sakta
    }else {
        return (res*1LL*res);
    }
}
int binExp(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
