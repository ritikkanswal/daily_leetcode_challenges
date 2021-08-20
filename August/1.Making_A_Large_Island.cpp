class Solution {
public:
    bool visited[502][502];
    int k=2;
    map<int,int>mp;
    int dfs(vector<vector<int>>&grid,int i,int j,int k)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||!grid[i][j]||visited[i][j])
            return 0;
        visited[i][j]=1;
        grid[i][j]=k;
        return 1+dfs(grid,i+1,j,k)+dfs(grid,i-1,j,k)+dfs(grid,i,j+1,k)+dfs(grid,i,j-1,k);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ma=0;
        bool flag=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 and !visited[i][j])
                {
                    int area=dfs(grid,i,j,k);
                    mp[k++]=area;
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                {
                    map<int,int>mp2;
                    int area=1;
                    if((i-1)>=0)
                    {
                        if(!mp2[grid[i-1][j]])
                        area+=mp[grid[i-1][j]];
                        mp2[grid[i-1][j]]++;
                    }
                        
                    if((j-1)>=0)
                    {
                        if(!mp2[grid[i][j-1]])
                        area+=mp[grid[i][j-1]];
                        mp2[grid[i][j-1]]++;
                    }
                    if((i+1)<r)
                    {
                        if(!mp2[grid[i+1][j]])
                        area+=mp[grid[i+1][j]];
                        mp2[grid[i+1][j]]++;
                    }
                    if((j+1)<c)
                    {
                        if(!mp2[grid[i][j+1]])
                        area+=mp[grid[i][j+1]];
                        mp2[grid[i][j+1]]++;
                    }
                    ma=max(ma,area);
                    flag=1;
                }
            }
        }
        if(!flag)
            return r*c;
        return ma;
    }
};