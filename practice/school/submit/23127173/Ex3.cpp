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

    vi parent(n), key(n);
    vb visited(n);

    PrimMST(adj, n, parent, key, visited);

    cout << "Edges in the MST and their weights:\n";
    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " \tWeight: " << adj[parent[i]][i] << "\n";
    }

    return 0;    
}
