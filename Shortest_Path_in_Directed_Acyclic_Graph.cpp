// Shortest Path in Directed Acyclic Graph

class Solution {
	private:
	void topoSort(vector<vector<pair<int, int>>> &adj, stack<int> &st, int vis[], int node){
	    vis[node] = 1;
	    for(auto it: adj[node]){
	        int v = it.first;
	        if(!vis[v]){
	            topoSort(adj, st, vis, v);
	        }
	    }
	    st.push(node);
	}
	public:
	vector<int> shortestPath(int V, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>>> adj(V);
		for (auto it: edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			
			adj[u].push_back({v, wt});
		}
		
// 		step 1: find the topo sort
		int vis[V] = {0};
		stack<int>st;
		for (int i = 0; i<V; i++) {
			if (!vis[i]) {
				topoSort(adj, st, vis, i);
			}
		}
		
// 		step 2: do the distance thing
		vector<int>dist(V, 1e9);
		dist[0] = 0;
		while(!st.empty()){
		    int node = st.top();
		    st.pop();
		    
		    for(auto it: adj[node]){
		        int v = it.first;
		        int wt = it.second;
		        
		        if(dist[node] + wt < dist[v]){
		            dist[v] = dist[node] + wt;
		        }
		    }
		}
		
		for(int i=0;i<V;i++){
		    if(dist[i] == 1e9){
		        dist[i] = -1
		    }    
		}
		
		return dist;
	}
};
