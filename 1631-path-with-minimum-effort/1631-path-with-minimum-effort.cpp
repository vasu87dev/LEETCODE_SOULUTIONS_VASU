class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
int m=heights.size();

int n=heights[0].size();

set<pair<int,pair<int,int>>>s;
vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));

dist[0][0]=0;
s.insert({0,{0,0}});
int max1=INT_MAX;
while(!s.empty())
{
    auto it=*s.begin();
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    int w=it.first;
int r=it.second.first;
int c=it.second.second;
s.erase(it);
for(int i=0;i<4;i++)
{
    int nr=r+row[i];
    int nc=c+col[i];

if(nr>=0 && nc>=0 && nr<m && nc<n )
{
    int maxi=max(abs(heights[nr][nc]-heights[r][c]),w);
    if(maxi<dist[nr][nc])
    {
        dist[nr][nc]=maxi;
            s.insert({dist[nr][nc],{nr,nc}});

    }


}





}


}


return dist[m-1][n-1];






















        
    }
};