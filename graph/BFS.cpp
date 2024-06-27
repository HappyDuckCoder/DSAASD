#include<iostream>
#include<queue>
#include<vector>

#define vi vector<int>
#define vpii vector<pair<int, int>>
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
}

void BFS(int u){
    queue<int> q;
    q.push(u); 

    while(!q.empty()){
        u = q.front();
        cout << u << " ";
        q.pop();
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
            }
        }
    }
}


int main(){

    init();
    BFS(1);

    return 0;
}
