/*
23CLC02 - 23127266 - NGUYEN ANH THU

Input:
Output:
*/
#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

void printPath(vector<int> &parent, int d)
{
    int v = d;
    while (parent[v] != -1)
    {
        cout << v << " ";
        v = parent[v];
    }
    cout << v;
}

void bfs(int s, int d, vector<pair<int, int>> a[], int n)
{
    queue<int> q;
    vector<bool> check(n, 0);
    vector<int> parent(n, -1);

    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        check[u] = 1;
        for (auto v : a[u])
        {
            if (!check[v.first])
            {
                parent[v.first] = u;
                if (v.first == d)
                {
                    printPath(parent, d);
                    return;
                }
                // cout << v.first << " " << u << "\n";
                q.push(v.first);
                check[v.first] = 1;
            }
        }
        q.pop();
    }
}

int main()
{
    ifstream inFile("test.inp");

    int n;
    inFile >> n;

    vector<pair<int, int>> a[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int weight;
            inFile >> weight;
            if (j > i && weight > 0)
            {
                a[i].push_back(make_pair(j, weight));
                a[j].push_back(make_pair(i, weight));
                // a
                cout << i << " " << j << "\n";
            }
        }
    }

    int s, d;
    inFile >> s >> d;
    inFile.close();

    bfs(s, d, a, n);
    return 0;
}