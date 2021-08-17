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
    int cnt=0;
    void helper(TreeNode * root,int ma)
    {
        if(!root)
            return;
        
        if(root->val>=ma)
        {
            cnt++;
            helper(root->left,root->val);
            helper(root->right,root->val);
        }
        else
        {
            helper(root->left,ma);
            helper(root->right,ma);
        }
    }
    int goodNodes(TreeNode* root) {
        helper(root,INT_MIN);
        return cnt;
    }
};