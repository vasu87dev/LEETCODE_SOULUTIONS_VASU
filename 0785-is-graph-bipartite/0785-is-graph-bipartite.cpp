class Solution {
private:
bool bfs(vector<vector<int>>& graph,int i,vector<int>&colour,queue<int>q)
{
    int node=i;
   // vis[i]=1;
    colour[i]=0;
q.push(i);
while(!q.empty())
{
int node=q.front();
q.pop();

    for(auto it : graph[node])
    {
        if( colour[it]==-1)
        {
            q.push(it);
            colour[it]=!colour[node];
        }

        else if(colour[it]==colour[node])
        {
            return false;
        }
    }
}
return true;
}

public:


    bool isBipartite(vector<vector<int>>& graph) {


int m=graph.size();


//vector<int>vis(m,0);
vector<int>colour(m,-1);
queue<int>q;
for(int i=0;i<m;i++)
{
    
    
        if(colour[i]==-1)
        {

            if(bfs(graph,i,colour,q)==false)
            {
                return false;
            }

        }
    
}
return true;












        
    }
};