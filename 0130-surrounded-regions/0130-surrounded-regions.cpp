class Solution {
private:
void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis)

{
    int n=board.size();
int m=board[0].size();
vis[row][col]=1;
int d[]={-1,0,1,0};
int e[]={0,1,0,-1};

for(int i=0;i<4;i++)
{
    int nr=row+d[i];
    int nc=col+e[i];
    if(nr>=0 && nr<n && nc>=0 && nc<m &&
    !vis[nr][nc] && board[nr][nc]=='O')
    {
        dfs(nr,nc,board,vis);
    }
}


}


public:


    void solve(vector<vector<char>>& board) {


int n=board.size();
int m=board[0].size();
vector<vector<int>>vis(n,vector<int>(m,0));
for(int i=0;i<m;i++)
{
     if(board[0][i]=='O')
     {
        dfs(0,i,board,vis);
     }

     if(board[n-1][i]=='O')
     {
        dfs(n-1,i,board,vis);


     }
}
for(int j=0;j<n;j++)
{
       
        if(board[j][0]=='O')
        {
            dfs(j,0,board,vis);
        }
    
    if(board[j][m-1]=='O')
    {
        dfs(j,m-1,board,vis);
    }
}



for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(!vis[i][j])
        
        {
            board[i][j]='X';
        }
    }
}



}



        
    
};