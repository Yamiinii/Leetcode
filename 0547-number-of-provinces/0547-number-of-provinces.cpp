class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);  // Initialize size of each set to 1
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Update the size of the merged set
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Update the size of the merged set
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
            size[ulp_u] += size[ulp_v];  // Update the size of the merged set
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        set<int> s;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            s.insert(ds.findUpar(i));  // Insert ultimate parents of each node into the set
        }

        return s.size();
    }
};
