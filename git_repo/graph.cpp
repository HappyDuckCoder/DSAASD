#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int u, v;
    int w;
};

void dfs();
void bfs();
void dijkstra();
void prim();

int main(){

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> list(V, vector<pair<int,int>> ());

    for(int i = 0; i < E; i++){
        int u, v, w; 
        cin >> u >> v >> w;
        list[u].push_back({v, w});
    }

    return 0;
}