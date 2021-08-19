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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            int mi=min(p->val,q->val);
            int ma=max(p->val,q->val);
            if(root->val>=mi and root->val<=ma)
                return root;
            if(root->val<mi)
                root=root->right;
            else
                root=root->left;
        }
        return nullptr;
    }
};