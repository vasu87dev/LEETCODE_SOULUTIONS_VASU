class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<int>inde(numCourses,0);
            vector<vector<int>> adj(numCourses);
    
    for(auto edge : prerequisites)
    {
        int u = edge[0];
        int v = edge[1];

        adj[v].push_back(u);
        inde[u]++;
    }
    // for(int i=0;i<V;i++)
    
    // {
    //     for(auto it: adj[i])
    //     {
    //         inde[it]++;
    //     }
    
    
    // }
queue<int> q;
for(int i=0;i<numCourses;i++)
{
    if(inde[i]==0)
    
    {
        q.push(i);
        
    }
    
}
int cnt=0;
vector<int>top;
while(!q.empty())
{
    int node=q.front();
    cnt++;
    q.pop();
    for(auto it : adj[node])
    {
        inde[it]--;
        if(inde[it]==0)
        {
            q.push(it);
        }
    }
   
}
if(cnt==numCourses)
{
    return true;
    
}
else
{
    return false;
}
}

        
    };


