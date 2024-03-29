//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	 vector<string> NBitBinary(int n){
        // code here
    int cnt1=0; int cnt0 =0; 
    vector<string>al;
    string curr="";
        
    fun(n, cnt1, cnt0, curr, al);
    return al;
        
    }
    void fun(int n , int cnt1, int cnt0, string cur,vector<string>& al ){
        if(n==0){
        al.push_back(cur);
        return;
        }
        
         fun(n - 1, cnt1 + 1, cnt0,cur+'1', al);

        if (cnt1 > cnt0) {
            // Create a new StringBuilder instance for each recursive call
            fun(n - 1, cnt1, cnt0 + 1, cur+'0', al);
        }
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends