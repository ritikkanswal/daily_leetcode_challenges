class Solution {
public:
    
    // n*k(log(k))+nlogn
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<vector<int>,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            vector<int>v(26);
            for(auto x:strs[i])
            {
                v[x-'a']++;
            }
            mp[v].push_back(strs[i]);
        }
        for(auto x:mp)
        {
            res.push_back(x.second);
        }
        return res;
    }
};