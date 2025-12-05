void DFSUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u])
        if (!visited[v])
            DFSUtil(v, adj, visited);
}

void DFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    DFSUtil(start, adj, visited);
}
