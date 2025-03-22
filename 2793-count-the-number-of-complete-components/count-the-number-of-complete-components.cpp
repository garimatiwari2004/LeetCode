class Solution {
public:
        void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& nodes, int& edges) {
    visited[node] = true;
    nodes++;
    edges += adj[node].size();
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, nodes, edges);
        }
    }
 }
    


int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    
    // Build adjacency list
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    int completeComponents = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int nodes = 0, edgesCount = 0;
            dfs(i, adj, visited, nodes, edgesCount);
            
            // Since each edge is counted twice, divide edgesCount by 2
            if (edgesCount / 2 == (nodes * (nodes - 1)) / 2) {
                completeComponents++;
            }
        }
    }
    
    return completeComponents;
    }
};