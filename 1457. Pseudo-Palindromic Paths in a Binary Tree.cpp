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
    bool check(vector<int>& mp) {
        int nm=0;
        for (auto it : mp) {
            if(it%2!=0)nm++;
        }
        if(nm<=1) return true;
        return false;
    }
    int solve(TreeNode* root, vector<int> path) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            path[root->val]++;
            if (check(path)) { return 1; }
            return 0;
        }
        path[root->val]++;
        int a = solve(root->left, path);
        int b = solve(root->right, path);
        return a + b;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> path(10, 0);
        return solve(root, path);
    }
};