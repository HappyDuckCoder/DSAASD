#include <iostream>
#include <vector>
#include <utility>
#define vi vector<int>
#define vii vector<vi>
#define vpii vector<pair<int, int>>

using namespace std;

int n = 6, m = 9;
vpii a = {{1,2},{1,3},{1,4},{2,4},{3,4},{3,5},{3,6},{4,6},{5,6}};

void displayGraphByAdjacencyMatrix(vii &g) {
    for(auto x : a) {
        g[x.first][x.second] = 1;
        g[x.second][x.first] = 1; 
    }
}

void displayGraphByAdjacencyList(vii &b) {
    for(auto x : a) {
        b[x.first].push_back(x.second);
        b[x.second].push_back(x.first);
    }
}

void displayEdgeList() {
    for(auto x : a) {
        cout << x.first << "-" << x.second << endl;
    }
}

void printAdjacencyMatrix(vii &g) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printAdjacencyList(vii &b) {
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 0; j < b[i].size(); j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vii g(n + 1, vi(n + 1, 0)); 

    displayGraphByAdjacencyMatrix(g);
    printAdjacencyMatrix(g);

    vii b(n + 1); 
    displayGraphByAdjacencyList(b);
    printAdjacencyList(b);

    displayEdgeList();

    return 0;
}
