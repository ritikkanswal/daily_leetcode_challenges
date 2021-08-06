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
    void flatten(TreeNode* root) {
        stack<TreeNode *>st;
        st.push(root);
        while(!st.size())
        {
            TreeNode *curr=st.top();
            st.pop();
            if(curr->right)
                st.push(root->right);
            if(curr->left)
                st.push(root->left);
            if(!st.empty())
                curr->right=st.top();
            curr->left=NULL;
        }
    }
};