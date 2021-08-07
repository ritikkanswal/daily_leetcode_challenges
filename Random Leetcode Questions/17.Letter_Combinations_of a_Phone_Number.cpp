class Solution {
public:
    map<char,vector<char>>mp;
    vector<string>res;
    void fun(int i,string digits,string k)
    {
        if(i==digits.size())
        {
            if(k.size())
            res.push_back(k);
            return;
        }
        vector<char>v=mp[digits[i]];
        for(int j=0;j<v.size();j++)
        {
            char x=v[j];
            fun(i+1,digits,k+x);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        fun(0,digits,"");
        return res;
    }
};