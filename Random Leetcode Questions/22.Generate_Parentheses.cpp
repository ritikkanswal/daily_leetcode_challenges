class Solution {
public:
    //n-->'('
    // m--> ')'
    vector<string> res;
    void fun(string str,int n,int m)
    {
        if(n==0 and m==0)
            res.push_back(str);
        if(n>0 and m>=n)
            fun(str+"(",n-1,m);
        if(m>0)
            fun(str+")",n,m-1);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        fun(s,n,n);
        return res;
    }
};