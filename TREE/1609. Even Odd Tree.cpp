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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool od_ev = true;
        while (!q.empty()) {
            int sz = q.size();
            TreeNode* first_Node = q.front();
            q.pop();
            int first_ele = first_Node->val;
            if(first_Node->left)q.push(first_Node->left);
            if(first_Node->right)q.push(first_Node->right);
            // if(sz==1)continue;
            if (od_ev) {
                if (first_ele % 2 == 0)
                    return false;
                for (int i = 1; i < sz; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    int ele = node->val;
                    if (first_ele >= ele || (ele % 2 == 0)) {
                        return false;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                    first_ele = ele;
                }
            } else {
                if (first_ele % 2 == 1)
                    return false;
                for (int i = 1; i < sz; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    int ele = node->val;
                    if (first_ele <= ele || (ele % 2 != 0)) {
                        return false;
                    }
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                    first_ele = ele;
                }
            }
            od_ev = !od_ev;
        }
        return true;
    }
};