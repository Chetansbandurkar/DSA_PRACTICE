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
    int solve(TreeNode*root,int&step){
        if(!root) return 0;

        int c1=solve(root->left,step);
        int c2=solve(root->right,step);

        step+=abs(c1)+abs(c2);

        return c1+c2+(root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        
        int step=0;

        solve(root,step);

        return step;
    }
};