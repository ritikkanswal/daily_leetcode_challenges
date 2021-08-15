class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>& nums,vector<int>v,vector<int>visited)
    {
        if(v.size()==nums.size())
        {
            res.push_back(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;
            v.push_back(nums[i]);
            visited[i]=1;
            helper(nums,v,visited);
            v.pop_back();
            visited[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>visited(nums.size());
        helper(nums,{},visited);
        return res;
    }
};