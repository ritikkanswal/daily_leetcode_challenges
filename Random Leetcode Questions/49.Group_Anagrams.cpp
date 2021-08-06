class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>tmp;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            tmp.push_back({s,strs[i]});
        }
        sort(tmp.begin(),tmp.end());
        string prev=tmp[0].first;
        int i=0;
        while(i<tmp.size())
        {
            vector<string>v;
            while(i<tmp.size())
            {
                if(tmp[i].first!=prev)
                {
                    i--;
                    break;
                }
                v.push_back(tmp[i++].second);
            }
            res.push_back(v);
            i++;
            if(i<tmp.size())
            prev=tmp[i].first;
        }
        return res;
    }
};

//Approach 2

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