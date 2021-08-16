class Solution {
public:
    vector<vector<int>>res;
    map<vector<int>,int>mp;
    void helper(vector<int>& candidates, int target,vector<int>v,int i)
    {
        if(target<0) return;
        if(target==0)
        {
            if(!mp[v])
            res.push_back(v);
            mp[v]++;
            return;
        }

        for(int j=i;j<candidates.size();j++)
        {
            if (j > i && candidates[j] == candidates[j - 1])
              continue;
            v.push_back(candidates[j]);
            helper(candidates,target-candidates[j],v,j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int &target) {
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,{},0);
        return res;
    }
};