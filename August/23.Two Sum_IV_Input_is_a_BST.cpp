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
    map<int,int>mp;
    void dfs(TreeNode *root,int k)
    {
        if(!root)
            return;
    
        mp[root->val]++;
        dfs(root->left,k);
        dfs(root->right,k);
    }
    
    bool Check(TreeNode *root,int target)
    {
        if(!root)
            return false;
        
        int val=root->val;
        if(mp[target-val])
            if(!(val==target-val and mp[target-val]==1))
            return true;
        return Check(root->left,target) or Check(root->right,target);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root,k);
        return Check(root,k);
    }
};