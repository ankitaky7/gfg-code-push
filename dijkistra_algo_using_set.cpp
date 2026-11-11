class Solution {
  public:
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        int v = adj.size();
        set<pair<int,int>>st;
        vector<int> dist(v, 1e9);
        
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = st.second;
            int dis = st.first;
            st.erase(it);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];
                
                if(dis + edgeW < dist[adjNode]){
                    // erase it if exited in the set
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});    
                    }
                    
                    dist[adjNode] = dis + edgeW;
                    st.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};