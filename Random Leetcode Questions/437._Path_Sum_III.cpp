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
    unordered_map<int,int>ump;
    void dfs(TreeNode* root, int targetSum,int sum,vector<int>v)
    {
        if(!root)
            return;
        
        sum+=root->val;
        if(ump[sum-targetSum])
            cnt+=ump[sum-targetSum];
        ump[sum]++;
        dfs(root->left,targetSum,sum,v);
        dfs(root->right,targetSum,sum,v);
        ump[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        ump[0]=1;
        dfs(root,targetSum,0,v);
        return cnt;
    }
};