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

void BellmanFord(const vii &adj, int n, vi &dist, vi &trace, int src) {
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        trace[i] = -1;
    }
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(adj[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]){
                    dist[v] = dist[u] + adj[u][v];
                    trace[v] = u;
                }
            }
        }
    }

    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            if(adj[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]){
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

    cout << "Duong di: ";
    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
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

    BellmanFord(adj, n, dist, trace, src);

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