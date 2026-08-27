class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis)

{
    int n=grid.size();
int m=grid[0].size();
vis[row][col]=1;
int d[]={-1,0,1,0};
int e[]={0,1,0,-1};

for(int i=0;i<4;i++)
{
    int nr=row+d[i];
    int nc=col+e[i];
    if(nr>=0 && nr<n && nc>=0 && nc<m &&
    !vis[nr][nc] && grid[nr][nc]==1)
    {
        dfs(nr,nc,grid,vis);
    }
}


}
public:
    int numEnclaves(vector<vector<int>>& grid) {

        
int n=grid.size();
int m=grid[0].size();
vector<vector<int>>vis(n,vector<int>(m,0));
for(int i=0;i<m;i++)
{
     if(grid[0][i]==1)
     {
        dfs(0,i,grid,vis);
     }

     if(grid[n-1][i]==1)
     {
        dfs(n-1,i,grid,vis);


     }
}
for(int j=0;j<n;j++)
{
       
        if(grid[j][0]==1)
        {
            dfs(j,0,grid,vis);
        }
    
    if(grid[j][m-1]==1)
    {
        dfs(j,m-1,grid,vis);
    }
}


int count=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(!vis[i][j] && grid[i][j]==1)
        
        {
            count++;
        }
    }
}


return count;
}
        
    
};