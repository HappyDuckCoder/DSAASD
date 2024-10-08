#include<iostream>
#include<vector>
#include<queue> 
#include<stack>
#include<cstring>

#define vi vector<int>
#define vii vector<vector<int>> 
#define vb vector<bool>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>

using namespace std;

const int __MAX__ = 1e6;

struct Edge {
    int u, v;
    int w;
};

void EdgeList_to_adjMatrix(const vector<Edge> &edges, vii &adj, int n, int m) {
    for (auto i : edges) {
        adj[i.u][i.v] = i.w;
        // Nếu đồ thị vô hướng, bỏ comment dòng dưới
        // adj[i.v][i.u] = i.w;
    }
}

void DFS(const vii &adj, int v, vb &visited) {
    cout << v << " ";
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[i] && adj[v][i] != __MAX__) {
            DFS(adj, i, visited);
        }
    }
}

void BFS(const vii &adj, int v, vb &visited) {
    queue<int> qu;

    qu.push(v);
    visited[v] = true;

    while (!qu.empty()) {
        int tmp = qu.front();
        cout << tmp << " ";
        qu.pop();

        for (int i = 0; i < adj[tmp].size(); i++) {
            if (!visited[i] && adj[tmp][i] != __MAX__) {
                qu.push(i);
                visited[i] = true;
            }
        }
    }
}

void dijkstra(const vii &adj, int n, vi &dist, vi &trace, vb &visited, int src) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = __MAX__;
        trace[i] = -1;
    }
    dist[src] = 0;

    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int i = 0; i < n; i++) {
            if (adj[u][i] != __MAX__ && !visited[i]) {
                int weight = adj[u][i];
                if (dist[u] + weight < dist[i]) {
                    dist[i] = dist[u] + weight;
                    trace[i] = u;
                    pq.push({ dist[i], i });
                }
            }
        }
    }
}

void printPath(int dest, const vi &trace) {
    stack<int> path;
    for (int v = dest; v != -1; v = trace[v]) {
        path.push(v);
    }

    cout << "Duong di: ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\n";
}

void PrimMST(const vii &adj, int n, vi &parent, vi &key, vb &visited) {
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;   
        visited[i] = false; 
        parent[i] = -1;     
    }

    key[0] = 0; 

    // Min-heap để tìm đỉnh có trọng số cạnh nhỏ nhất, cấu trúc là {key[i], i}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true; 

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && adj[u][v] < key[v] && !visited[v]) {
                key[v] = adj[u][v]; 
                pq.push({key[v], v}); 
                parent[v] = u; 
            }
        }
    }
}

void BellmanFord(const vii &adj, int n, vi &dist, vi &trace, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        trace[i] = -1;
    }
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adj[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    trace[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                cout << "Do thi co chu trinh am!" << endl;
                return;
            }
        }
    }
}


int main() {
    int n, m;
    cout << "Nhap so dinh va canh: ";
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u1, v1, w1;
        cin >> u1 >> v1 >> w1;
        edges.push_back({ u1, v1, w1 });
    }

    vii adj(n, vi(n));
    vb visited(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = (i == j) ? 0 : __MAX__; 
        }
    }

    EdgeList_to_adjMatrix(edges, adj, n, m);

    cout << "Ma tran ke:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == __MAX__) {
                cout << "INF "; 
            } else {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }

    DFS(adj, 0, visited); cout << endl;
    fill(visited.begin(), visited.end(), false);
    BFS(adj, 0, visited); cout << endl;

    vi dist(n);
    vi trace(n);
    fill(visited.begin(), visited.end(), false); 
    int src; cout << "Nhap src: "; cin >> src;

    dijkstra(adj, n, dist, trace, visited, src);

    cout << "Khoang cach ngan nhat tu dinh " << src << " den cac dinh khac:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == __MAX__) {
            cout << "Den dinh " << i << ": Khong the di chuyen\n";
        } else {
            cout << "Den dinh " << i << ": " << dist[i] << "\n";
            printPath(i, trace);
        }
    }

    vi parent(n); 
    vi key(n);
    fill(visited.begin(), visited.end(), false); 

    cout << "Canh cua cay khung toi thieu (MST):\n";
    for (int i = 1; i < n; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " \tWeight: " << adj[parent[i]][i] << "\n";
    }

    fill(visited.begin(), visited.end(), false); 
    fill(dist.begin(), dist.end(), false); 
    fill(trace.begin(), trace.end(), false); 

    cout << "Khoang cach ngan nhat tu dinh " << src << " den cac dinh khac:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Den dinh " << i << ": Khong the di chuyen\n";
        } else {
            cout << "Den dinh " << i << ": " << dist[i] << "\n";
            printPath(i, trace);
        }
    }

    return 0;
}
