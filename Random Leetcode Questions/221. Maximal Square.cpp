class Solution {
public:
    int dp[1002][1002];
    int fun(vector<vector<char>>& matrix,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int r=matrix.size();
        int c=matrix[0].size();
        if(i>=r or j>=c)
            return dp[i][j]=0;
        if(matrix[i][j]=='1')
            return dp[i][j]=1+min(fun(matrix,i+1,j),min(fun(matrix,i,j+1),fun(matrix,i+1,j+1)));
        else
            return dp[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int r=matrix.size();
        int c=matrix[0].size();
        int ma=INT_MIN;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int val=fun(matrix,i,j);
                ma=max(ma,val);
            }
        }
        return ma*ma;
    }
};