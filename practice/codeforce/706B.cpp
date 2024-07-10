#include<iostream>
#include<vector>
#include<algorithm>

#define vi vector<int> 

using namespace std;

int lowerbound(vi &a, int n, int x){
    if(a[0] > x) return 0;
    
    int l = 0, r = n - 1;
    
    while(l < r){
        int m = (l + r) / 2 + 1;
        if(a[m] > x) r = m - 1;
        else l = m;
    }
    
    return l + 1;
}

int main(){
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int t = lowerbound(a, n, x);
        cout << t << "\n";
    }
        
    return 0;
}