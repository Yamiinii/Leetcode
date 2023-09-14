//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Disjointset{
    public:
    vector<int> rank,parent,size;
    public:
    Disjointset(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findUpar(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findUpar(parent [node]);
    }
    
    void unionbyrank(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]<rank[ulp_v])
        parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
        parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }


};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjointset ds(n);
        int extras=0;
        for(auto it:edge)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v))
            {
                extras++;
            }
            else
            {
                ds.unionbyrank(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            cntC++;
        }
        int ans=cntC-1;
        if(ans<=extras)
        return ans;
        else
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends