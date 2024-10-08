#include<iostream>
#include<vector> 

#define vi vector<int> 
#define vii vector<vector<int>> 
#define vpii vector<pair<int, int>> 

const int __MAX__ = 1e9;

using namespace std;

struct Edge{
    int u, v;  
    int w; 
};

void EdgeList_to_adjMatrix(const vector<Edge> &edges, vii &adj, int n, int m){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = __MAX__;
        }
    }
    for(auto i : edges){
        adj[i.u][i.v] = i.w;
    }
}

void EdgeList_to_adjEdge(const vector<Edge> &edges, vector<vpii> &adjEdge, int n, int m){
    for(auto i : edges){
        pair<int, int> tmp; 
        tmp.first = i.v;
        tmp.second = i.w;
        adjEdge[i.u].push_back(tmp);
        // neu la do thi vo huong thi them dong adjEdge[i.v].push_back({i.u, i.w})
    }   
}

void adjMatrix_to_adjEdge(const vii &adj, vector<vpii> &adjEdge, int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj[i][j] != __MAX__){
                pair<int, int> tmp;
                tmp.first = j;
                tmp.second = adj[i][j];
                adjEdge[i].push_back(tmp);
            }
        }
    }
}

void adjMatrix_to_EdgeList(const vii &adj, vector<Edge> &edges, int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj[i][j] != __MAX__){
                Edge tmp;
                tmp.u = i;
                tmp.v = j;
                tmp.w = adj[i][j];
                edges.push_back(tmp);
            }
        }
    }
}

int main(){

    int n; cout << "nhap so dinh: "; cin >> n; 
    int m; cout << "nhap so canh: "; cin >> m;

    vector<Edge> edges;

    for(int i = 0; i < m; i++){
        int u1, v1, w1; 
        cin >> u1 >> v1 >> w1;
        Edge tmp;
        tmp.u = u1; tmp.v = v1; tmp.w = w1;
        edges.push_back(tmp);
    } 

    vii adj(n + 1, vi(n + 1));
    EdgeList_to_adjMatrix(edges, adj, n, m);

    vector<vpii> adjEdge(n + 1);
    // EdgeList_to_adjEdge(edges, adjEdge, n, m);

    // adjMatrix_to_adjEdge(adj, adjEdge, n, m);
    // for(auto i : adjEdge){
    //     for(int j = 0; j < i.size(); j++){
    //         cout << i[j].first << " " << i[j].second << " haha ";
    //     }
    //     cout << endl;
    // }

    vector<Edge> egdes2;
    adjMatrix_to_EdgeList(adj, egdes2, n, m);

    for(auto i : egdes2){
        cout << i.u << " " << i.v << " " << i.w << "\n";
    }

    return 0;
}

