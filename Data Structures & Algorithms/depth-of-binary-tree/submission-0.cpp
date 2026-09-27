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
    int maxDepth(TreeNode* root,int ans=0) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = maxDepth(root->left,ans) + 1;
        int right = maxDepth(root->right,ans) + 1;
        ans=max({ans,right,left});
        return ans;
    }
};
