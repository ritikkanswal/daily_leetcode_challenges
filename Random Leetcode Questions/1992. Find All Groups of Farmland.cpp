class Solution {
public:
    bool visited[302][302];
    int v1=-1,v2=-1;
    int dp[302][302];
    void dfs(vector<vector<int>>& land,int i,int j)
    {
        int r=land.size();
        int c=land[0].size();
        if(visited[i][j])
            return;
        
        if(i>=r or j>=c)
            return;
        
        visited[i][j]=1;
        
        if(land[i][j]!=1)
            return;
        
        dfs(land,i+1,j);
        dfs(land,i,j+1);
        
        v1=max(v1,i);
        v2=max(v2,j);
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int r=land.size();
        int c=land[0].size();
        vector<vector<int>>res;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(land[i][j]==1 and !visited[i][j])
                {
                    // visited[i][j]=1;
                    dfs(land,i,j);
                    res.push_back({i,j,v1,v2});
                    v1=-1;
                    v2=-1;
                }
            }
        }
        return res;
    }
};