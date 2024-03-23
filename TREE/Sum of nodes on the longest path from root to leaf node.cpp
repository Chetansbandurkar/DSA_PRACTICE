//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node*root,int len,int sm,int&mxSm,int&mxLen){
        if(!root){
            if(mxLen<len){
                mxLen=len;
                mxSm=sm;
            }
            else if(mxLen==len&& mxSm<sm){
                mxSm=sm;
            }
            
            return ;
        }
        solve(root->left,len+1,sm+root->data,mxSm,mxLen);
        solve(root->right,len+1,sm+root->data,mxSm,mxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root)return 0;
        int mxSm=INT_MIN,mxLen=0;
        solve(root,0,0,mxSm,mxLen);
        
        return mxSm;
    }
};
class Solution
{
public:
    pair<int,int> height(Node*root){
        if(!root)return {0,0};
        auto lh=height(root->left);
        
        auto rh=height(root->right);
        int sum=root->data;
        if(lh.first==rh.first){
            sum+=lh.second>rh.second?lh.second:rh.second;
        }
        else if(lh.first>rh.first){
            sum+=lh.second;
        }
        else{
            sum+=rh.second;
        }
        
        return {max(rh.first,lh.first)+1,sum };
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto ans=height(root);
        return ans.second;
        
    }
};
//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends