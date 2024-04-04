class Solution {
public:
// LEETCODE
    long long merge(vector<int>&a,int l,int md,int r){
        int n1=md+1-l;
        int n2=r-md;
        int left[n1];
        int right[n2];
        for(int i=0;i<n1;i++){
            left[i]=a[l+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=a[md+1+i];
        }
        int k=l;
        int i=0,j=0;
        int cnt=0;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                a[k]=left[i];
                // k++;
                i++;
            }else{
                a[k]=right[j];
                cnt+=n1-i;// kyuki uske age ke bhi to grater hoge n 
                j++;
            }
            k++;
        }

        while(i<n1){
            a[k++]=left[i++];
        }
        while(j<n2){
            a[k++]=right[j++];
        }
        return cnt;
    }
    long long  mergSort(vector<int>&a,int l,int r){
        long long res=0;
        if(l<r){
            int m=l+(r-l)/2;
            res+=mergSort(a,l,m);
            res+=mergSort(a,m+1,r);
            res+=merge(a,l,m,r);
        }

        return res;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int localInv = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                localInv++;
            }
        }

        int globalInv = mergSort(nums,0,n-1);
        // cout<<globalInv<<endl;

        if(localInv == globalInv) return true;
        return false;

    }
};