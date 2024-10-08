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

    return 0;
}
