//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> v(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(v[i]==-1)
	        {
	            queue<int> q;
	            q.push(i);
	            v[i]=1;
	            while(!q.empty())
	            {
	                int front =q.front();
	                q.pop();
	                for(auto it:adj[front])
	                {
	                    if(v[it]==-1)
	                    {
	                        v[it]=1-v[front];
	                        q.push(it);
	                    }
	                    else if(v[it]==v[front])
	                    return false;
	                    
	                }
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends