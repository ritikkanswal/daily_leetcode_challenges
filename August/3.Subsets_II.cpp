class Solution {
public:
    void helper(vector<int>& nums,vector<int>v,set<vector<int>>&res,int i)
    {
        if(i==nums.size())
        {
            res.insert(v);
            return;
        }
        res.insert(v);
        helper(nums,v,res,i+1);
        v.push_back(nums[i]);
        helper(nums,v,res,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<vector<int>>ans;
        vector<int>v;
        helper(nums,v,res,0);
        for(auto x:res)
        {
            vector<int>vp;
            for(auto y:x)
            {
                vp.push_back(y);
            }
            ans.push_back(vp);
        }
        return ans;
    }
};