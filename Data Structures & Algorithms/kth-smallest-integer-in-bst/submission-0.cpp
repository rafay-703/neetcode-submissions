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


    int kthSmallest(TreeNode* root, int& k,int ans=-1) {
        if(!root) return ans;
        ans = kthSmallest(root->left,k,ans);
        if(k==0) return ans;
        k--;
        if(k==0)  
        {
            cout << "updating ans "<<root->val<<" : "  << ans << endl;
            ans=root->val;
            return ans;
        }
        ans = kthSmallest(root->right,k,ans);
    
        return ans;
        
    }
};
