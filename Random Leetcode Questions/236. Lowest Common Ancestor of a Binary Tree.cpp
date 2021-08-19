/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * lca(TreeNode* root, TreeNode* p,TreeNode *q)
    {
        if(!root)
            return nullptr;
        
        if(root==p || root==q)
            return root;
        
        TreeNode * Left=lca(root->left,p,q);
        TreeNode * Right=lca(root->right,p,q);
        
        if(Left!=NULL and Right!=NULL)
            return root;
        
        if(Left!=NULL)
            return Left;
        else
            return  Right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};