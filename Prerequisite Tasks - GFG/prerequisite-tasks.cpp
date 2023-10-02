//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here int vis[V]={0};
	     vector<vector<int>> adj(N);

    for (const auto& edge : prerequisites) {
        int u = edge.first;
        int v = edge.second;

        // Assuming nodes are 0-based
        adj[u].push_back(v);
        // If the graph is undirected, you can also add the reverse edge
        // adjList[v].push_back(u);
    }
	    
	    
	   vector<int> indegree(N, 0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int front=q.front();
	        q.pop();
	        topo.push_back(front);
	        
	        for(auto it:adj[front])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    return topo.size()==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends