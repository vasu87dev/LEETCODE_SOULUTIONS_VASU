class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
vector<vector<vector<int>>>adj(n);
for(auto it: roads)
{
    adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});

}
vector<long>dist(n,LLONG_MAX);
set<pair<long long,int>>s;
dist[0]=0;
s.insert({0,0});
vector<int>way(n,0);
way[0]=1;
int mode=int(1e9+7);
while(!s.empty())
{

    auto it=*s.begin();
    int node=it.second;
    long long w=it.first;
    
s.erase(it);

for(auto it: adj[node])
{
long long h=it[1];
    if(w+h<dist[it[0]])
    {
        dist[it[0]]=w+it[1];




        
        s.insert({dist[it[0]],it[0]});
        way[it[0]]=way[node];
    }    
    
    
        else if(w+it[1]==dist[it[0]])
{
    way[it[0]]=(way[node]+way[it[0]])%mode;
}


    }
    }



return way[n-1];

    }
};