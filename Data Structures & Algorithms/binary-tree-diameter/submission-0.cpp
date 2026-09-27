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
    int dfs(TreeNode* root,int& ans)
    {
        if(!root)
        {
            return 0;
        }
        int sc =0,left=0,right=0;
        if(root->left)
        {
            left = dfs(root->left,ans)+1;
        }
        if(root->right)
        {
            right = dfs(root->right,ans)+1;
        }
        ans = max(ans,left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root,int ans=0) {
        dfs(root,ans);
        return ans;
   }
};
