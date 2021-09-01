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
    int Max(vector<int>&nums,int start,int end)
    {
        int idx=0,ma=INT_MIN;
        for(int i=start;i<=end;i++)
        {
            if(ma<nums[i])
            {
                ma=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* fun(vector<int>&nums,int start,int end)
    {
        if(start>end) return NULL;
        int mid=Max(nums,start,end);
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=fun(nums,start,mid-1);
        root->right=fun(nums,mid+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
};