class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>>adj(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>dist(V, -1);
        
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(dist[it] == -1){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist[dest];
    }
};
