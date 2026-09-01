class Solution {
private:
bool dfs(vector<vector<int>>& graph,int i,vector<int>&colour)
{
int start=i;

for(auto it: graph[start])
{

    if(colour[it]==-1)
    {
        colour[it]=!colour[start];
        if(dfs(graph,it,colour)==false)
        {
            return false;
        }
    }
         else if(colour[it] == colour[start])
        {
            return false;
        }

    }

return true;






}
public:


    bool isBipartite(vector<vector<int>>& graph) {


int m=graph.size();


//vector<int>vis(m,0);
vector<int>colour(m,-1);
//queue<int>q;
for(int i=0;i<m;i++)
{
    
    
        if(colour[i]==-1)
        {

colour[i]=0;
            if(dfs(graph,i,colour)==false)
            {
                return false;
            }

        }
    
}
return true;












        
    }
};