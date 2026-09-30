class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
vector<vector<int>>rev(graph.size());
vector<int>inde(graph.size()
);
for(int i=0;i<graph.size();i++)
{
for(auto it : graph[i])
 {
rev[it].push_back(i);
inde[i]++;

 }   
}
queue<int>q;
for(int i=0;i<graph.size();i++)
{
    if(inde[i]==0)
    {
        q.push(i);
    }
}
vector<int>ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: rev[node])
        {
            inde[it]--;
            if(inde[it]==0)
            {
                q.push(it);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans;
    
    }
};