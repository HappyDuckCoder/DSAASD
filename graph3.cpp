#include<iostream>
#include<vector>
#include<queue>
#include<stack>

#define vi vector<int>
#define vb vector<bool>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

const int __MAX__ = 1e9;

using namespace std;

void dijkstra(const vii &adj, int n, vi &dist, vi &trace, vb &visited, int src){
    for(int i = 0; i < n; i++){
        dist[i] = __MAX__;
        trace[i] = -1;
    }
    dist[src] = 0;

    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, src});

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
                    pq.push({dist[i], i}); 
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

    cout << "Duong di: ";
    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\n";
}

int main(){
    int n;
    cout << "Nhap so dinh: "; 
    cin >> n;
    
    vii adj(n, vi(n)); 
    
    cout << "Nhap ma tran ke: \n"; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
            if(adj[i][j] == 0 && i != j){
                adj[i][j] = __MAX__; 
            }
        }
    }

    int src; 
    cout << "Nhap dinh bat dau: ";
    cin >> src;

    vi dist(n);
    vi trace(n);
    vb visited(n, false); 

    dijkstra(adj, n, dist, trace, visited, src);

    cout << "Khoang cach ngan nhat tu dinh " << src << " den cac dinh khac:\n";
    for(int i = 0; i < n; i++){
        if(dist[i] == __MAX__){
            cout << "Den dinh " << i << ": Khong the di chuyen\n";
        } else {
            cout << "Den dinh " << i << ": " << dist[i] << "\n";
            printPath(i, trace);
        }
    }

    return 0;
}
