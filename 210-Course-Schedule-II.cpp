class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

vector<vector<int>>adj(numCourses);
vector<int>inde(numCourses,0);
for(auto it:prerequisites)
{
    int u=it[0];
    int v=it[1];
 adj[v].push_back(u);
inde[u]++;
} int cnt=0;
queue<int>q;
for(int i=0;i<numCourses;i++)
{
    if(inde[i]==0)
    {
        q.push(i);
    }
}
vector<int>top;
while(!q.empty())
{
int node=q.front();
top.push_back(node);
q.pop();
cnt++;

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
    
        return top;
}
else
{

    return {};
}
    }
};