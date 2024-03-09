//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code her
	    int l=0,h=n-1;
	    int ans=-1;
	    if(arr[0]>arr[1]) return 1;
	    while(l<=h){
	        int md=(l+h)/2;
	       // cout<<md<<endl;/
	        
	       if(arr[md]>=arr[l] && arr[md]>=arr[h]){
	           ans=md;
	           l=md+1;
	       }
	       else{
	           h=md;
	       }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends