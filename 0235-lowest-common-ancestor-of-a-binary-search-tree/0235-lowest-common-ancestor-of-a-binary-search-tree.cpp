/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;

        if (root == p)
            return p;
        if (root == q)
            return q;

        TreeNode* l = solve(root->left, p, q);

        TreeNode* r = solve(root->right, p, q);

        if (l && r)
            return root;

        if (l)
            return l;

        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};