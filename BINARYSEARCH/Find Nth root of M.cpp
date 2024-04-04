//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int s=1;
	    int e=m;
	    while(s<=e){
	        int md=(s+e)/2;
	        
	        if(pow(md,n)==m){
	            return md;
	        }
	        else if(pow(md,n)>m){
	            e=md-1;
	        }
	        else{
	            s=md+1;
	        }
	    }
	    
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends