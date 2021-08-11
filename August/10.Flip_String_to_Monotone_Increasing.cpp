class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int z=0,res=0;
        int sz=s.size();
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='0') z++;
            else res++;
            
            res=max(res,z);
        }
        return sz-res;
    }
};