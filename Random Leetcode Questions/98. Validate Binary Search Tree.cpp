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
    long prev=INT_MIN;
    bool FirstTime=1;
    bool inorder(TreeNode *root)
    {
        if(!root)
            return 1;
        bool x=inorder(root->left);
        if(FirstTime)
        {
            prev=root->val;
            FirstTime=0;
        }
        else
        {
             if(prev>=root->val)
              return 0;
             prev=root->val;
        }
       
       
        bool y=inorder(root->right);
        
        return x&y;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};