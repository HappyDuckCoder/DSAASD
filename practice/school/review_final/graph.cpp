#include<iostream>
#include<vector>
#include<queue>
#include<stack>

#define vi vector<int> 
#define vii vector<vector<int>> 
#define vb vector<bool> 
#define pii pair<int, int> 
#define vpii vector<pii>

using namespace std;

const int __MAX__ = 1e6;

void DFS(const vii &adj, int v, vb &visited){
    visited[v] = true;
    cout << v << " ";
    for(int i = 0; i < adj[v].size(); i++){
        if(adj[v][i] != __MAX__ && !visited[i]){
            DFS(adj, i, visited);
        }
    }
}

void BFS(const vii &adj, int v, vb &visited) {
    queue<int> qu;

    qu.push(v);
    visited[v] = true;

    while(!qu.empty()){
        int tmp = qu.front();
        cout << tmp << " ";
        qu.pop();

        for(int i = 0; i < adj[tmp].size(); i++){  
            if(adj[tmp][i] != __MAX__ && !visited[i]){
                qu.push(i);
                visited[i] = true;
            }
        }
    }
}

void dijkstra(const vii &adj, int n, vi &dist, vi &trace, vb &visited, int src) {
    for(int i = 0; i < n; i++){
        visited[i] = false;
        dist[i] = __MAX__;
        trace[i] = -1;
    }
    dist[src] = 0;

    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({ 0, src });

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(int i = 0; i < n; i++){
            if(adj[u][i] != __MAX__ && !visited[i]){
                int weight = adj[u][i];
                if(dist[u] + weight < dist[i]){
                    dist[i] = dist[u] + weight;
                    trace[i] = u;
                    pq.push({ dist[i], i });
                }
            }
        }
    }
}

void BellmanFord(const vii &adj, int n, vi &dist, vi &trace, int src) {
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        trace[i] = -1;
    }
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(adj[u][v] != INT_MAX && dist[u] != __MAX__ && dist[u] + adj[u][v] < dist[v]){
                    dist[v] = dist[u] + adj[u][v];
                    trace[v] = u;
                }
            }
        }
    }

    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            if(adj[u][v] != INT_MAX && dist[u] != __MAX__ && dist[u] + adj[u][v] < dist[v]){
                cout << "Do thi co chu trinh am!" << endl;
                return;
            }
        }
    }
}

void printPath(int dest, const vi &trace){
    stack<int> path;
    for(int v = dest; v != -1; v = trace[v]){
        path.push(v);
    }

    while(!path.empty()){
        cout << path.top();
        path.pop();
        if(!path.empty()) cout << "->";
    }
    cout << "\n";
}

void PrimMST(const vii &adj, int n, vi &parent, vi &key, vb &visited){
    for(int i = 0; i < n; i++){
        key[i] = INT_MAX;   
        visited[i] = false; 
        parent[i] = -1;     
    }

    key[0] = 0; 

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); 

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        visited[u] = true; 

        for(int v = 0; v < n; v++){
            if(adj[u][v] != 0 && adj[u][v] < key[v] && !visited[v]){
                key[v] = adj[u][v]; 
                pq.push({key[v], v}); 
                parent[v] = u; 
            }
        }
    }
}

void input_adj_matrix(vii &a, int &n){
    cin >> n;
    vii adj(n, vi(n, __MAX__));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int weight;
            cin >> weight;
            if(weight != 0) {
                adj[i][j] = weight;
            } else if (i == j) {
                adj[i][j] = 0; 
            }
        }
    }
    a = adj;
}

int main(){

    int n;
    vii adj;
    input_adj_matrix(adj, n);

    vb visited(n, false);
    vi dist(n);
    vi trace(n);

    int src; 
    cout << "Nhap dinh xuat phat (src): "; 
    cin >> src;

    dijkstra(adj, n, dist, trace, visited, src);
    // BellmanFord(adj, n, dist, trace, src);

    cout << "Khoang cach ngan nhat tu dinh " << src << " den cac dinh khac:\n";
    for(int i = 0; i < n; i++){
        if(dist[i] == __MAX__){
            cout << "Den dinh " << i << ": Khong the di den\n";
        } else {
            cout << "Den dinh " << i << ": " << dist[i] << "\n";
            cout << "Duong di: "; 
            printPath(i, trace);
        }
    }

    vi parent(n), key(n);
    // vb visited(n);

    PrimMST(adj, n, parent, key, visited);

    cout << "Edges in the MST and their weights:\n";
    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " \tWeight: " << adj[parent[i]][i] << "\n";
    }

    return 0;
}
