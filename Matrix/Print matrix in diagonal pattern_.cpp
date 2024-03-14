//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n=mat.size();
         vector<int>ans;
         bool flag=true;
         for(int i=0;i<n;i++){
             int st=ans.size();
             int a=0,b=i;
             while(a<n && b>=0){
                 ans.push_back(mat[a][b]);
                 a++;
                 b--;
             }
             if(flag)reverse(ans.begin()+st,ans.end());
             flag=!flag;
         }
         
         for(int i=1;i<n;i++){
             int st=ans.size();
             int a=i,b=n-1;
             while(a<n && b>=0){
                 ans.push_back(mat[a][b]);
                 a++;b--;
             }
             if(flag)reverse(ans.begin()+st,ans.end());
             flag=!flag;
         }
         
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends