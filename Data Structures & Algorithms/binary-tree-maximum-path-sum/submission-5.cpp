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
    int best(TreeNode* root,int& ans) {
        
        if(!root) return INT_MIN+10000;
        if(!root->left && !root->right)
        {
            int num =root->val;
            ans = max(ans,num); 
            return num;
        }
        auto left = best(root->left,ans);
        auto right = best(root->right,ans);
        ans = max({ans,right+left+root->val,right,left,root->val+left,root->val+right,root->val});
        return max({root->val+left,root->val+right,root->val});
    }
    int maxPathSum(TreeNode* root) {
        int ans =INT_MIN+10000;
        best(root,ans);
        return ans;
    }
};
