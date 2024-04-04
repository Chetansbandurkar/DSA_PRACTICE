// GFG
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

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
    void inordere(Node*root,vector<int>&a){
        if(!root)return;
        inordere(root->left,a);
        a.push_back(root->data);
        inordere(root->right,a);
    }
    int pairsViolatingBST(int n, Node *root) {
      vector<int>a;
      inordere(root,a);
      int globalInv = mergSort(a,0,n-1);
      return globalInv;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends