class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

int m=grid.size();
int n=grid[0].size();
int vis[m][n];
int ans=0;

queue<pair<pair<int,int>,int>>q;
 
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(grid[i][j]==2)
        {
            q.push({{i,j},0});
            vis[i][j]=2 ;
       }
       else
       {
        vis[i][j]=0;
       }
    }
}

  while(!q.empty())
  {
    int r=q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
    ans=max(ans,t);
q.pop();

int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};
for(int i=0;i<4;i++)
{
    int nr=r+a[i];
    int nc=c+b[i];

if(nr>=0 &&nr<m && nc>=0 && nc<n && vis[nr][nc]==0 &&grid[nr][nc]==1)
{
    q.push({{nr,nc},t+1});
    vis[nr][nc]=2;

}

}
  }
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if((grid[i][j]==1) && vis[i][j]!=2 )
        {
            return -1;
        }




  
}
  }
    
return ans;





  



  }

        
    
};