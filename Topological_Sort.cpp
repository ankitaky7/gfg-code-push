class Solution {
	private:
	void dfs(vector<vector<int>> & adj, int node, int vis[], stack<int> &st){
	    vis[node] = 1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(adj, it, vis, st);
	        }
	    }
	    st.push(node);
	}
	public:
	vector<int> topoSort(vector<vector<int>> & adj) {
		stack<int>st;
		int v = adj.size();
		int vis[v] = {0};
		for (int i = 0; i < v; i++) {
			if (!vis[i]) {
				dfs(adj, i, vis, st);
			}
		}
		
		vector<int>ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};