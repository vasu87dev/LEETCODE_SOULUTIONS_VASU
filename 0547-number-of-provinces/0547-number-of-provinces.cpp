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
    int findCircleNum(vector<vector<int>>& isConnected) {
DisjointSet ds(isConnected.size());
for(int i=0;i<isConnected.size();i++)
{
    for(int j=0;j<isConnected.size();j++)
         
         {
            if(isConnected[i][j] == 1)
            {
                ds.unionBySize(i+1,j+1);
            }
         }
}
int cnt=0;
for(int i=1;i<=isConnected.size();i++)
{
    if(ds.parent[i]==i)
    {
        cnt++;
    }
}
return cnt;
    }
};