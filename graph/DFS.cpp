#include<iostream>
#include<vector> 

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vb vector<bool> 

using namespace std;

int n, m;
vb visited(1001, false);
vi adj[1001];

void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
} 

void DFS(int u){
    cout << u << " ";
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v]) 
            DFS(v);
}

int main(){
    init();
    DFS(1);

    return 0;
}