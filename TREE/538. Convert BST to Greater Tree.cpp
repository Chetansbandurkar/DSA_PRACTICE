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
    int sum=0;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->right);
            sum+=root->val;
            root->val=sum;
            inorder(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        sum=0;
        inorder(root);
        return root;
    }
};