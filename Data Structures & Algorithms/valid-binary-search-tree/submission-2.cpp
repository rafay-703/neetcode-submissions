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
    bool isValidBST(TreeNode* root,int mn = INT_MIN,int mx = INT_MAX) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        bool ans = isValidBST(root->left,mn,root->val-1) && isValidBST(root->right,root->val+1,mx);
        if(root->left)
        {
           ans &= (root->val > root->left->val) & (root->left->val >= mn) & (root->left->val<=mx); 
        }
        if(root->right)
        {
           ans &= (root->val < root->right->val) & (root->right->val >= mn) & (root->right->val<=mx);     
        }
        return ans;
    }
};
