class Solution {
public:
    int mod=1e9+7;
    long long kadane(vector<int>&a){
        int ans=a[0];
        if(a[0]<0)a[0]=0;
        ans=max(ans,a[0]);
        for(int i=1;i<a.size();i++){
            a[i]+=a[i-1];
            if(a[i]<0)a[i]=0;
            ans=max(ans,a[i]);
        }
        return ans;
    }
    // to get max pref sum and max suff sum;
    pair<long long ,long long > getMaxes(vector<int>&a,long long sum){
        long long maxPrefSum=0;
        long long maxSuffSum=sum;
        long long curPrefSum=0,curSuffSum=sum;
        for(int i=0;i<a.size();i++){
            curPrefSum+=a[i];
            curSuffSum-=a[i];
            maxPrefSum=max(maxPrefSum,curPrefSum);
            maxSuffSum=max(maxSuffSum,curSuffSum);
        }
        return {maxPrefSum,maxSuffSum};
    }
    int handlePositiveSum(vector<int>&a,int k,long long sum){
        pair<long long ,long long>maxes=getMaxes(a,sum);
        long long maxSum=kadane(a);
        if(k==1){
            return maxSum%mod;
        }else{
            long long ans=(1ll*(k-2)*sum)%mod;
            ans=(ans+maxes.first+maxes.second)%mod;
            return ans;
        }
    }
    int handleNegativeSum(vector<int>&a,int k,long long sum){
        pair<long long ,long long >maxes=getMaxes(a,sum);

        long long ans=kadane(a);

        if(k==1) return ans%mod;
        return max(ans,maxes.first+maxes.second);
    }
    int kConcatenationMaxSum(vector<int>& a, int k) {
        long long sum=0;
        for(auto it:a)sum+=it;

        if(sum>=0){
            return handlePositiveSum(a,k,sum);
        }
        else{
            return handleNegativeSum(a,k,sum);
        }
        // return 0;
    }
};