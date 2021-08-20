class Solution {
public:
    bool visited[52][52];
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||!grid[i][j])
            return 0;
        
        if(visited[i][j]) return 0;
        
        visited[i][j]=1;
        
        return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ma=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 and !visited[i][j])
                {
                    int area=dfs(grid,i,j);
                    ma=max(ma,area);
                }
            }
        }
        return ma;
    }
};