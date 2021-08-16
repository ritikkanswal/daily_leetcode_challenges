class Solution {
public:
    string minWindow(string s, string t) {
        string res,tmp;
        map<char,int>mp1,mp2;
        int mct=0,dmct=t.size();
        for(auto x:t)
        {
            mp2[x]++;
        }
        int i=-1,j=-1;
        while(1)
        {
            bool flag1=0;
            bool flag2=0;
            int sz=s.size();
            while(i<sz and mct<dmct)
            {
                i++;
                flag1=1;
                mp1[s[i]]++;
                if(mp1[s[i]]<=mp2[s[i]])
                    mct++;
            }  
            while(j<i and mct==dmct)
            {
                res=s.substr(j+1,i-j);
                if(tmp.size()==0 || res.size()<tmp.size())
                    tmp=res;
                j++;
                flag2=1;
                mp1[s[j]]--;
                if(mp1[s[j]]<mp2[s[j]])
                    mct--;
            } 
            if(!flag1 and !flag2)
                break;
        }
        return tmp;
    }
};