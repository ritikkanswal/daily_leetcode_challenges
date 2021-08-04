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
    vector<vector<int>>res;
    void dfs(TreeNode* root, int targetSum,vector<int>p,int sum)
    {
        if(!root)
            return;
        p.push_back(root->val);
        sum+=root->val;
        if(sum==targetSum and !root->left and !root->right)
            res.push_back(p);
        dfs(root->left,targetSum,p,sum);
        dfs(root->right,targetSum,p,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>p;
        dfs(root,targetSum,p,0);
        return res;
    }
};