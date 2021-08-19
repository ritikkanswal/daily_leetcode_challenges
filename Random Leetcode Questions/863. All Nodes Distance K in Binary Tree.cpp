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
    map<TreeNode *,int>visited;
    map<TreeNode *,TreeNode *>parent;
    vector<int>res;
    void bfs(TreeNode *root,int k)
    {
        if(visited[root] or k<0 or !root)
            return;
        visited[root]=1;
        if(k==0)
            res.push_back(root->val);
        
        if(parent[root])
            bfs(parent[root],k-1);
        bfs(root->left,k-1);
        bfs(root->right,k-1);
    }
    void inorder(TreeNode * root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        if(root->left)
            parent[root->left]=root;
        if(root->right)
            parent[root->right]=root;
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        
        bfs(target,k);
        return res;
    }
};