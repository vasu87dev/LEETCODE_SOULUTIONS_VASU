class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
vector<vector<vector<int>>>adj(n);
for(auto it:flights)
{
    adj[it[0]].push_back({it[1],it[2]});


}






vector<int>price(n,INT_MAX);
vector<int>steps;


queue<pair<int,pair<int,int>>>s;
s.push({0,{src,0}});
while(!s.empty())
{
    auto it=s.front();
int st=it.first;
int node=it.second.first;
int p=it.second.second;
s.pop();


if(st>k ) continue;
for(auto it:adj[node])
{
    if(p+it[1]<=price[it[0]]  && st<=k)
    {
        price[it[0]]=p+it[1];
        s.push({st+1,{it[0],price[it[0]]}});
        
        
    }
}
}
if(price[dst]==INT_MAX)
{
    return -1;
}
return price[dst];
    }
};