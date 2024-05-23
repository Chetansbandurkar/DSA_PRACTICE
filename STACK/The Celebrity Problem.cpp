//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        // select the people which can be celb 
        // as there is the only one person cel 
        // so we can choose one cel
        while(st.size()!=1){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(M[a][b]){
                // matlab b cel he as b is known to a;
                st.push(b);
            }else{
                st.push(a);
                // if not b rhen a con't be as b is not known to a;
            }
        }
        
        int might_be_cel=st.top();st.pop();
        
        // heck for each  the 0's and 1's in 
        // row->0,(col->1,expect,might_be_cel)
        
        for(int i=0;i<n;i++){
            if(M[might_be_cel][i]!=0) return -1;
        }
        
        for(int i=0;i<n;i++){
            if(M[i][might_be_cel]!=1 && i!=might_be_cel) return -1;
        }
        
        return might_be_cel;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends