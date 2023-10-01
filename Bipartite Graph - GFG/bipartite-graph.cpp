//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 bool dfs(vector<int>adj[],int i,vector<int> &coloured,int color)
    {
        coloured[i]=color;
        for(auto it:adj[i])
        {if(coloured[it]==-1)
               { if(dfs(adj,it,coloured,1-color)==false)
                    return false;
               } else if(coloured[it]==coloured[i])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	      vector<int> coloured(V,-1);
        for(int i=0;i<V;i++)
        {
            if(coloured[i]==-1)
               { if(dfs(adj,i,coloured,1)==false)
                    return false;}
            
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