//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Create a set to store pairs of distances and nodes.
        set<pair<int, int>> st;
        
        // Initialize the dist vector with a large value for all vertices.
        vector<int> dist(V, 1e9);
        
        // Insert the pair {0, S} into the set to start the algorithm.
        st.insert({0, S});
        dist[S] = 0;
       
        while (!st.empty()) {
            // Extract the element with the smallest distance.
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            // Iterate through adjacent nodes.
            for (auto i : adj[node]) {
                int edgeWeight = i[1];
                int adjNode = i[0];
                
                if (dis + edgeWeight < dist[adjNode]) {
                    // If the distance is updated, remove and insert the updated distance.
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends