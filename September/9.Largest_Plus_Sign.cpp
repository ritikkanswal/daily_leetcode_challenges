class Solution {
public:
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mine) {
        
        
        int mines[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mines[i][j]=1;
            }
        }
        
        for(auto x:mine)
        {
            mines[x[0]][x[1]]=0;
        }
        // cout<<mines[4][2]<<endl;
        int ma=0;
        
        //for left
        int dp_L[502][502];
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(mines[i][j]==1)
                    cnt++;
                else
                    cnt=0;
                dp_L[i][j]=cnt;
            }
        }
        
        //for right
        int dp_R[502][502];
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            for(int j=n-1;j>=0;j--)
            {
                if(mines[i][j]==1)
                    cnt++;
                else
                    cnt=0;
                dp_R[i][j]=cnt;
            }
        }
        
        //for down
        int dp_D[502][502];
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(mines[j][i]==1)
                    cnt++;
                else
                    cnt=0;
                dp_D[j][i]=cnt;
            }
        }
        
        //for top
        int dp_T[502][502];
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            for(int j=n-1;j>=0;j--)
            {
                if(mines[j][i]==1)
                    cnt++;
                else
                    cnt=0;
                dp_T[j][i]=cnt;
            }
        }
        
        
        // LOGIC
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mines[i][j]==1)
                {
                    int l,r,t,d;
                    l=dp_L[i][j];
                    r=dp_R[i][j];
                    t=dp_T[i][j];
                    d=dp_D[i][j];
                    ma=max(ma,min(min(l,r),min(t,d)));
                }
            }   
        }
        return ma;
    }
};