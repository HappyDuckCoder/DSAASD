#include<iostream>
#include<vector>
#define vi vector<int> 

using namespace std;

int solve(const vi &a, int n){
    int l = 1, r = n;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == m) return m;
        else if(a[m] < m) l = m + 1;
        else r = m - 1; 
    }
    return -1;
}

int main(){

    int n; cin >> n;
    vi a(n + 1); 
    a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];

    // cout << 1;

    int t = solve(a, n);

    cout << t;

    return 0;
}