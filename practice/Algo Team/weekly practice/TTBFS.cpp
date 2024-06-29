#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define vi vector<int>
#define vb vector<bool>

using namespace std;

int n, m;
vi adj[1001];
vb visited(1001, false);

void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
}

void BFS(int start){
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(start);

    while(!q.empty()){
        int u = q.top();
        q.pop();

        if(visited[u]) continue;  

        cout << u << "\n";
        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
            }
        }

    }
}

int main() {
    init();
    
    for(int i = 1; i <= n; i++){
        if(!visited[i] && !adj[i].empty()){
            BFS(i);
        }
    }

    return 0;
}
