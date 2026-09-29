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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int& preI,int i , int j)
    {
        if(i>j) return nullptr;
        TreeNode* root = new TreeNode(preorder[preI++]);
        int mid = find(inorder.begin(),inorder.end(),root->val) - inorder.begin();
        root->left = build(preorder,inorder,preI,i,mid-1);
        root->right = build(preorder,inorder,preI,mid+1,j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        int preI=0;
        return build(preorder,inorder,preI,0,preorder.size()-1);
    
    }
};
