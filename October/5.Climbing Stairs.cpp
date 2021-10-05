class Solution {
public:
    int res=0;
    int dp[46];
    int fun(int n)
    {
        if(n==0)
            return 1;
        else if(n<0) 
            return 0;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fun(n-1)+fun(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(n);
    }
};