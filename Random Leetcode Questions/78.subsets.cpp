class Solution {
public:
    void helper(vector<int>& nums,vector<int>v,vector<vector<int>>&res,int i)
    {
        if(i==nums.size())
        {
            res.push_back(v);
            return;
        }
        helper(nums,v,res,i+1);
        v.push_back(nums[i]);
        helper(nums,v,res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        helper(nums,v,res,0);
        return res;
    }
};