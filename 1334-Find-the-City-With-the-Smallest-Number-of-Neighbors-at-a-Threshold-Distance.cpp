class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
    for(auto it:edges)
    {

    int p=it[0];
    int q=it[1];
    int r=it[2];
    matrix[p][q]=r;
    matrix[q][p]=r;
    
}
for(int i=0;i<n;i++)
{
matrix[i][i]=0;
}


for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<n;k++)
        {
        
if(matrix[j][i] != INT_MAX && matrix[i][k] != INT_MAX)
{
            long long c=matrix[j][i]+matrix[i][k];
            long long d=matrix[j][k];
            matrix[j][k]=min(c,d);

       
 }
  }
    }
}
int ans=-1;
int ans1=INT_MAX;
for(int i=0;i<n;i++)
{ int count=0;
for(int j=0;j<n;j++)
{
    if(matrix[i][j]<=distanceThreshold)
    {
        count++;
    }
    
    }
    if(count<=ans1)
    {
        ans1=count;
        ans=i;
    }


}
    
    return ans;
}
};