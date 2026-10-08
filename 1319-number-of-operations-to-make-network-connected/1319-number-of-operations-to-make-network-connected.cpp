class DisjointSet {
public:
    vector<int> rank, parent, size;
 

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find the ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
         
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) 
          
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
    
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
int extra=0;
DisjointSet ds(n);

for(auto it : connections)
{

    if(ds.findUPar(it[0])==ds.findUPar(it[1]))
    {
        extra++;
    }
    else
    {
    ds.unionBySize(it[0],it[1]);
    }
}
int cnt=0;
for(int i=0;i<n;i++)

{
    

    if(ds.parent[i]==i)
    {
cnt++;
    }

}
int ans=cnt-1;
if(extra>=ans)
{
    return ans;
}
else
{
    return -1;
}


        
    }
};