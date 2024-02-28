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
int ans,depth=0;
    void dfs(TreeNode*root,int level){
        if(!root)return ;
        if(level==depth){
            ans=root->val;
            depth++;
        }

        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
    //    DFS
        dfs(root,0);
        return ans;
    }
};
// BFS->
//  queue<TreeNode*>q;
//         int lftval=0;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode*node=q.front();
//             lftval=node->val;
//             int sz=q.size();
//             for(int i=0;i<sz;i++){
//                 TreeNode*nd=q.front();
//                 q.pop();
//                 if(nd->left){
//                     q.push(nd->left);
//                 }
//                 if(nd->right){
//                     q.push(nd->right);
//                 }
//             }
//         }

//         return lftval;