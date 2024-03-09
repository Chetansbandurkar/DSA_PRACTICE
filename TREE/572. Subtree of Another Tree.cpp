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
    bool ans=false;
    bool isSame(TreeNode*root,TreeNode*subRoot){
        if(!root && !subRoot){
            return true;
        }

        if(!root || !subRoot || root->val!=subRoot->val){
            return false;
        }

        bool l=isSame(root->left,subRoot->left);
        bool r=isSame(root->right,subRoot->right);

        return l&r;
    }
    void dfs(TreeNode*root,TreeNode*subRoot){
        if(!root)return ;

        if(root->val==subRoot->val){
            if(ans!=true){
                ans=isSame(root,subRoot);
            }
        }
        dfs(root->left,subRoot);
        dfs(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return ans;
    }
};

// OPTIMIZE APPROACH

//  int expandString(string s, int i,int j)
//    {
//        int count=0;
//        while(i>=0 && s[i]==s[j]&&j<s.length())
//        {
//            count++;
//            i--;
//            j++;
//        }
//        return count;

//    }
    
//     int countSubstrings(string s) {
//         // int i=0;
//        int count=0;
//        for(int i=0;i<s.length();i++)
//        {
//            int oddKa=expandString(s,i,i);
//            count+=oddKa;
//            int evenKa=expandString(s,i,i+1);
//            count+=evenKa;
//        }
//        return count;
//     }