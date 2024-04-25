/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode*root,int&val,int&depth,int dpt){
        if(dpt>=depth || !root)return ;

        if(dpt==depth-1)
        {
            TreeNode*tmp=root->left;
            root->left=new TreeNode(val);
            root->left->left=tmp;

            TreeNode*tmpp=root->right;
            root->right=new TreeNode(val);
            root->right->right=tmpp;
        }

        solve(root->left,val,depth,dpt+1);
        solve(root->right,val,depth,dpt+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1){
          TreeNode* newNode=new TreeNode(val);
          newNode->left=root;
          return newNode;
       }
       solve(root,val,depth,1);

       return root;
    }
};