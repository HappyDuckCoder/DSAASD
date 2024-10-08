#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define vi vector<int> 
#define vii vector<vector<int>> 
#define vb vector<bool> 
#define pii pair<int, int> 
#define vpii vector<pii>

const int __MAX__ = 1e6;

struct Edge{
    int u, v;
    int w;
};

// em se lam tren trong so duong

void DFS(const vii &adj, int u, vb &visited){
    cout << u << " ";
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        if(!visited[i] && adj[u][i] != __MAX__){
            DFS(adj, i, visited);
        }
    }
}

void BFS(const vii &adj, int u, vb &visited){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;

    while(!qu.empty()){
        int tmp = qu.front();
        cout << tmp;
        qu.pop();

        for(int i = 0; i < adj[tmp].size(); i++){
            if(!visited[i] && adj[tmp][i] != __MAX__){
                qu.push(i);
                visited[i] = true;
            }
        }
    }
}

void dijkstra(const vii &adj, int n, vi &dist, vi &trace, vb &visited, int src){
    for(int i = 0; i < n; i++){
        dist[i] = __MAX__;
        visited[i] = false;
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
            if(!visited[i] && adj[u][i] != __MAX__){
                int weight = adj[u][i];
                if(dist[u] + weight < dist[i]){
                    dist[i] = dist[u] + weight;
                    trace[u] = i;
                    pq.push({ dist[i], i });
                }
            }
        }
    }
}

// void PRIM()

void reset(vb &visited){
    for(int i = 0; i < visited.size(); i++){
        visited[i] = false;
    }
}

int main(){
    int n, m;
    cout << "nhap so dinh, canh: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    for(int i = 0; i < m; i++){
        int u1, v1, w1;
        cin >> u1 >> v1 >> w1;
        Edge tmp; 
        tmp.u = u1, tmp.v = v1, tmp.w = w1;
        edges.push_back(tmp); 
    }

    vii adj(n, vi(n, __MAX__));
    vii list(n);

    for(auto i : edges){
        adj[i.u][i.v] = i.w;
    }

    for(auto i : edges){
        list[i.v].push_back(i.w);
    }

    vb visited = {false};
    DFS(adj, 0, visited);
    reset(visited);
    BFS(adj, 0, visited);
    

    return 0;
}