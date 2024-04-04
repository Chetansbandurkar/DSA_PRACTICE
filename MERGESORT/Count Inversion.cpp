//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long a[],long long l,long long md,long long  r){
        long long  n1=md+1-l;
        long long  n2=r-md;
        long long  left[n1];
        long long  right[n2];
        for(int i=0;i<n1;i++){
            left[i]=a[l+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=a[md+1+i];
        }
        long long  k=l;
        long long  i=0,j=0;
        long long  cnt=0;
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
    long long mergSort(long long a[],int l,int r){
        long long int res=0;
        if(l<r){
            long long  m=l+(r-l)/2;
            res+=mergSort(a,l,m);
            res+=mergSort(a,m+1,r);
            res+=merge(a,l,m,r);
        }

        return res;
    }
    long long int inversionCount(long long a[], long long N)
    {
       long long int globalInv = mergSort(a,0,N-1);
       
       return globalInv;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends