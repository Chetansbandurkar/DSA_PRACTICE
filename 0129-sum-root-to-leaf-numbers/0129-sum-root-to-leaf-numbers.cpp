/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int num) {

        if(!root) return 0;
        if (!root->left && !root->right) {
            return num * 10 + root->val;
        }

        return solve(root->left, num * 10 + root->val) +
               solve(root->right, num * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return solve(root, 0);
    }
};