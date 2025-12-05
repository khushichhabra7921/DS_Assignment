struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[b] < rank[a]) parent[b] = a;
        else parent[b] = a, rank[a]++;
    }
};

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void Kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), cmp);
    DSU d(V);

    cout << "Edges in MST:\n";
    for (auto &e : edges) {
        if (d.find(e.u) != d.find(e.v)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            d.unite(e.u, e.v);
        }
    }
}
