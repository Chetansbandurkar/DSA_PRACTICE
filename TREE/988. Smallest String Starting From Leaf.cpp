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
    string res = "|";
    void solve(TreeNode* root, string cur) {
        if (!root)
            return;
        cur = string(1, root->val + 'a') + cur;
        if (!root->left && !root->right) {
            res = min(cur, res);
        }
        solve(root->left, cur);
        solve(root->right, cur);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return res;
    }
};