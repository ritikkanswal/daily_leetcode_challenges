class Solution {
public:
    vector<vector<int>>res;
    map<vector<int>,int>mp;
    void helper(vector<int>& nums,vector<bool>visited,vector<int>tmp)
    {
        if(tmp.size()==nums.size())
        {
            if(!mp[tmp])
                res.push_back(tmp);
            mp[tmp]++;
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;
            visited[i]=1;
            tmp.push_back(nums[i]);
            helper(nums,visited,tmp);
            visited[i]=0;
            tmp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>visited(nums.size());
        helper(nums,visited,{});
        return res;
    }
};