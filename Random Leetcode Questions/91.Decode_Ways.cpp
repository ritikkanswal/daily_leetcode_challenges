class Solution {
public:
    int dp[1001];
    int fun(string s,int idx)
    {
        if(dp[idx]!=-1) 
            return dp[idx]; 
        if(s.size()==idx)
            return 1;
        if(s[idx]=='0')
            return 0;
        if(s.size()-idx==1)
            return 1;
        int way1=fun(s,idx+1);
        int way2=0;
        int val=stoi(s.substr(idx,2));
        if(val<=26)
        way2=fun(s,idx+2);
        dp[idx]=way1+way2;
        return dp[idx];
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s,0);
    }
};