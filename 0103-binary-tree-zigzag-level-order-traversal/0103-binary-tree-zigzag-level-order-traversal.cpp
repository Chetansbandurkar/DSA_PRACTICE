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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        bool LtoR_dir = true;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> t;
        while (!q.empty()) {
            int width = q.size();
            vector<int> tmp;
            for (int i = 0; i < width; i++) {
                TreeNode* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            if(LtoR_dir)
            ans.push_back(tmp);
            else{
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
            }
            LtoR_dir = !LtoR_dir;
        }

        return ans;
    }
};