// Given a directed graph with V vertices, numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[u] contains all vertices reachable from vertex u through a directed edge, check whether the graph contains a cycle.

// Note: The graph may have multiple connected components. Self-loops are allowed, but repeated edges are not allowed.





class Solution {
    private:
    bool dfsCheck(vector<vector<int>> & adj, int node, int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCheck(adj, it, vis, pathVis) == true) return true;
                // means it is visited previosly
            }else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
	public:
	bool isCyclic(vector<vector<int>> & adj) {
		// code here
		int v = adj.size();
		int vis[v] = {0};
		int pathVis[v] = {0};
		for (int i = 0; i<v; i++) {
			if(!vis[i]){
			    if(dfsCheck(adj, i, vis, pathVis) == true) return true;
			}
		}
		return false;
	}
};
