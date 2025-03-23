class Solution {
public:
   const int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);  // Adjacency list {neighbor, time}
    
    // Build the graph
    for (auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    // Min-heap {time, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> dist(n, LLONG_MAX);  // Stores shortest time to each node
    vector<int> ways(n, 0);  // Stores number of ways to reach each node

    // Start from node 0
    pq.push({0, 0});
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty()) {
        auto [currTime, node] = pq.top();
        pq.pop();

        // Skip if not optimal (Dijkstra's property)
        if (currTime > dist[node]) continue;

        // Traverse neighbors
        for (auto& [neighbor, time] : adj[node]) {
            long long newTime = currTime + time;

            if (newTime < dist[neighbor]) {
                dist[neighbor] = newTime;
                ways[neighbor] = ways[node]; // New shortest path found
                pq.push({newTime, neighbor});
            } 
            else if (newTime == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[node]) % MOD; // Another shortest path found
            }
        }
    }

    return ways[n - 1];
}
};