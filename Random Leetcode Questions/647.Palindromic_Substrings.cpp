class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        bool dp[s.size()][s.size()];
        for(int g=0;g<s.size();g++)
        {
            for(int i=0,j=g;j<s.size();i++,j++)
            {
                if(g==0)
                    dp[i][j]=1;
                if(g==1)
                    dp[i][j]=(s[i]==s[j]);
                if(g>=2)
                    dp[i][j]=s[i]==s[j] && dp[i+1][j-1];
                
                if(dp[i][j])
                count++;
            }
        }
        return count;
    }
};