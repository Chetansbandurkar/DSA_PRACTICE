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
    int mxD(TreeNode*root){
        if(!root) return 0;
        int l=mxD(root->left);
        int r=mxD(root->right);

        return max(l,r)+1;
    }
    TreeNode* dfs(TreeNode*root,int mx_depth,int level){
        if(!root) return NULL;
        if(mx_depth-1==level) return root;

        TreeNode* left=dfs(root->left,mx_depth,level+1);
        TreeNode* right=dfs(root->right,mx_depth,level+1);

        if(left && right)  return root;
        return left?left:right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mx_depth=mxD(root);
        return dfs(root,mx_depth,0);
    }
};