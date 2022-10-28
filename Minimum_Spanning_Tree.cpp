//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> par;
    void makesets(int V)
    {
        vector<int> p(V,0);
        for(int i=0;i<V;i++)
        {
            p[i]=i;
        }
        par=p;
        return;
    }
    
    void unionn(int x, int y)
    {
        int u=findpar(x);
        int v=findpar(y);
        
        par[u]=v;
    }
    
    int findpar(int node)
    {
        if(node==par[node])return node;
        return par[node]=findpar(par[node]);
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        makesets(V);
        vector<vector<int>> ad;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                ad.push_back({adj[i][j][1],i,adj[i][j][0]});
            }
        }
        sort(ad.begin(),ad.end());
        
        int res=0;
        for(int i=0;i<ad.size();i++)
        {
            if(findpar(ad[i][1])!=findpar(ad[i][2]))
            {
                res+=ad[i][0];
                unionn(ad[i][1],ad[i][2]);
            }
        }
        return res;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
