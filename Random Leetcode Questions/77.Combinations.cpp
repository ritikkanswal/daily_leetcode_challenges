class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>&v,int k,vector<int>tmp,int i)
    {
        if(tmp.size()==k)
        {
            res.push_back(tmp);
            return;
        }
        if(i==v.size())
            return;
        for(int j=i;j<v.size();j++)
        {
            tmp.push_back(v[j]);
            helper(v,k,tmp,j+1);  
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)
            v.push_back(i);
        helper(v,k,{},0);
        return res;
    }
};