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
    TreeNode*
    MapParentChild(TreeNode* root,
                   unordered_map<TreeNode*, TreeNode*>& childParentMap,
                   int& start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = NULL;
        childParentMap[root] = NULL;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start) {
                target = node;
            }
            if (node->left) {
                childParentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                childParentMap[node->right] = node;
                q.push(node->right);
            }
        }

        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> childParentMap;
        unordered_map<TreeNode*, bool> alreadyBurned;
        TreeNode* target = MapParentChild(root, childParentMap, start);
        alreadyBurned[target] = 1;
        queue<TreeNode*> q;
        int T = 0;
        q.push(target);
        while (!q.empty()) {
            bool isBurned = false;

            int sz = q.size();
            for (int i = 0; i < sz; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (childParentMap[node] &&
                    !alreadyBurned[childParentMap[node]]) {
                    isBurned = 1;
                    alreadyBurned[childParentMap[node]] = 1;
                    q.push(childParentMap[node]);
                }

                if (node->left && !alreadyBurned[node->left]) {
                    alreadyBurned[node->left] = 1;
                    q.push(node->left);
                    isBurned = true;
                }

                if (node->right && !alreadyBurned[node->right]) {
                    alreadyBurned[node->right] = 1;
                    q.push(node->right);
                    isBurned = 1;
                }
            }

            if (isBurned)
                T++;
        }

        return T;
    }
};