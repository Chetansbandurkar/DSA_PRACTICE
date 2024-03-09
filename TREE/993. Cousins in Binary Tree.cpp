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
    void dfs(TreeNode*root,int&depthY,int&depthX,int&ParentY,int&ParentX,int&x,int&y,int parent,int lvl){
        if(!root)return ;

        if(root->val==x){
            depthX=lvl;
            ParentX=parent;
            return;
        }
        if(root->val==y){
            depthY=lvl;
            ParentY=parent;
            return;
        }
        dfs(root->left,depthY,depthX,ParentY,ParentX,x,y,root->val,lvl+1);
        dfs(root->right,depthY,depthX,ParentY,ParentX,x,y,root->val,lvl+1);
    }
    // x and y at same level  and have different parent /
    bool isCousins(TreeNode* root, int x, int y) {
        int depthY,ParentY;
        int depthX,ParentX;
        dfs(root,depthY,depthX,ParentY,ParentX,x,y,-1,0);
        if(depthY==depthX && ParentX!=ParentY){
            return true;
        }
        return false;
    }
};