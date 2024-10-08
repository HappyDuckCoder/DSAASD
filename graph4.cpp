/*input
4 4
1 2 1
2 3 2
3 4 3
4 1 4
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fi first
#define se second
#define pii pair<int, int> 

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m;
vector <pair<int, int>> g[N];

int dis[N]; // mảng d lưu khoảng cách của toàn bộ đỉnh

int prim(int s){ 
    int ret = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    for(int i = 1; i <= n; i++) dis[i] = INF;

    dis[s] = 0;
    q.push({0, s});

    while(!q.empty()){
        auto top = q.top(); 
        q.pop();
        int curDis = top.fi; 
        int u = top.se;

        if(curDis != dis[u]) continue;

        ret += dis[u]; 
        dis[u] = -INF;

        for(auto &e : g[u]){
            int v = e.fi; 
            int c = e.se;
            if(dis[v] > c){
                dis[v] = c;
                q.push({ dis[v], v });
            }
        }
    }
    return ret;
}
int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    cout << prim(1) << '\n';

    return 0;
}