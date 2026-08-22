class Solution {
private:
  vector<vector<int>> bfs(vector<vector<int>>& mat,vector<vector<int>>&vis,vector<vector<int>>&check,queue<pair<pair<int,int>,int>>q)
{
    
    while(!q.empty())
    {
    int a=q.front().first.first;
    int b=q.front().first.second;
    int count=q.front().second;
    check[a][b]=count;
    q.pop();
    
int e[4]={-1,0,1,0};
int f[4]={0,1,0,-1};

for(int i=0;i<4;i++)
{
    int nr=a+e[i];
    int nc=b+f[i];
    if(nr>=0 && nr<vis.size() && nc>=0 && nc<vis[0].size() && vis[nr][nc]!=1 && mat[nr][nc]!=0)
    {
       
        vis[nr][nc]=1;
     
         q.push({{nr,nc},count+1});
    } 
   
}
    }






    
    return check;

}






public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {


        int n=mat.size();
        int m=mat[0].size();



vector<vector<int>> vis(n, vector<int>(m, 0));
vector<vector<int>> check(n, vector<int>(m, 0));

queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
 return bfs(mat,vis,check,q);






        
    }
};