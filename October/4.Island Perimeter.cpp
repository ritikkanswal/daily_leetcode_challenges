class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    if(i+1>=r or grid[i+1][j]==0)
                    cnt++;
                    if(i-1<0 or grid[i-1][j]==0)
                    cnt++;
                    if(j+1>=c or grid[i][j+1]==0)
                    cnt++;
                    if(j-1<0 or grid[i][j-1]==0)
                    cnt++;
                }
            }
        }
        return cnt;
    }
};