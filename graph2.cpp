#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define vi vector<int>
#define vb vector<bool>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>

const int __MAX__ = 1e9;

using namespace std;

void DFS(const vii &adj, int v, vb &visited){
    visited[v] = true;
    cout << v << " ";
    for(int i = 0; i < adj[v].size(); i++){
        if(adj[v][i] == 1 && !visited[i]){
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
            if(adj[tmp][i] == 1 && !visited[i]){
                qu.push(i);
                visited[i] = true;
            }
        }
    }
}

void adjMatrix_to_adjEdge(const vii &adj, vii &adjEdge, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adj[i][j] == 1){
                adjEdge[i].push_back(j);
            }
        }
    }
}

void DFS2(const vii &adjEdge, int v, vb &visited){
    cout << v << " ";
    visited[v] = true;

    for(auto i : adjEdge[v]){
        if(!visited[i]){
            DFS2(adjEdge, i, visited);
        }
    }
}

void BFS2(const vii &adjEdge, int v, vb &visited){
    queue<int> qu;

    qu.push(v);
    visited[v] = true;

    while(!qu.empty()){
        int tmp = qu.front();
        qu.pop();
        cout << tmp << " ";

        for(auto i : adjEdge[tmp]){
            if(!visited[i]){
                BFS2(adjEdge, i, visited);
            }
        }
    }

}

int main() {
    int n;
    cout << "Nhap so dinh: "; 
    cin >> n;
    
    vii adj(n, vi(n)); 
    vb visited(n, false); 
    
    cout << "Nhap ma tran ke: \n"; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "DFS traversal: ";
    DFS(adj, 0, visited); 
    cout << "\n";

    fill(visited.begin(), visited.end(), false);

    cout << "BFS traversal: ";
    BFS(adj, 0, visited); 
    cout << "\n";

    vii adjEdge(n); 
    adjMatrix_to_adjEdge(adj, adjEdge, n);

    fill(visited.begin(), visited.end(), false);
    cout << "DFS2 traversal: ";
    DFS2(adjEdge, 0, visited); 
    cout << "\n";

    fill(visited.begin(), visited.end(), false);
    cout << "DFS2 traversal: ";
    DFS2(adjEdge, 0, visited); 
    cout << "\n";


    return 0;
}
