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
    int sum;
    void solve(TreeNode*root,int flg){
        if(!root){
          return ;
        }

        if(!root->left && !root->right && flg){
            sum+=root->val;
        }

        solve(root->left,1);
        solve(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,0);
        return sum;
    }
};