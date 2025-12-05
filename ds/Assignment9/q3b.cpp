#include <climits>

void Prim(vector<vector<pair<int,int>>>& adj, int V) {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> mst(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mst[u] = true;

        for (auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if (!mst[v] && w < key[v])
                key[v] = w, parent[v] = u;
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << endl;
}
