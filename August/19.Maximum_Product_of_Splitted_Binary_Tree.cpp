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
    long long WholeSum=0;
    long long ma=-1;
    long long inorder(TreeNode *root)
    {
        if(!root)
            return 0;
        return root->val+inorder(root->right)+inorder(root->left);
        
    }
    long long dfs(TreeNode * root)
    {
        if(!root) 
            return 0;
        long long l=dfs(root->left);
        long long r=dfs(root->right);
        long long SubTreeSum=root->val+l+r;
        ma=max(ma,((WholeSum-SubTreeSum)*SubTreeSum));
        return SubTreeSum;
    }
    int maxProduct(TreeNode* root) {
        WholeSum=inorder(root);
        dfs(root);
        return ma%(1000000000+7);
    }
};