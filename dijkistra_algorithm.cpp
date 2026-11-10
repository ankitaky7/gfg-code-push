class Solution {
	public:
	vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		int v = adj.size();
		vector<int> dist(v, 1e9);
		
		dist[src] = 0;
		pq.push({0, src});
		
		while (!pq.empty()) {
			int dis = pq.top().first;
			int node = pq.top().second;
			pq.pop();
			
			if (dis > dist[node]) continue;
			
			for (auto it: adj[node]) {
				int adjNode = it[0];
				int edgeWeight = it[1];
				
				if (dis + edgeWeight < dist[adjNode]) {
					dist[adjNode] = dis + edgeWeight;
					pq.push({dist[adjNode], adjNode});
				}
			}
		}
		return dist;
	}
};
