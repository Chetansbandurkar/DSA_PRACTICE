//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &m1, vector<vector<int>> &m2, int n, int x)
	{
	    int r1=0,c1=0;
	    int r2=n-1,c2=n-1;
	    int cnt=0;
	    while(r1<n && r2>=0){
	        int sm=m1[r1][c1]+m2[r2][c2];
	        if(sm==x){
	            cnt++;
	            c2--;
	            c1++;
	        }
	        if(sm<x){
	            c1++;
	        }
	        if(sm>x){
	            c2--;
	        }
	        if(c1==n){
               c1=0; r1++;
           }
           
           if(c2==-1){
               c2=n-1; r2--;
           }
	    }
	    
	    return cnt;
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
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends