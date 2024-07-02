#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

#define ll long long
#define vll vector<ll>

using namespace std;

ll getMin(vll &a, int n){
    ll minVal = LLONG_MAX;  
    for(int i = 0; i < n; i++){
        minVal = min(minVal, a[i]);
    }
    return minVal;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vll a(n);
        vll b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        ll minA = getMin(a, n);
        ll minB = getMin(b, n);

        ll cnt = 0;

        for(int i = 0; i < n; i++){
            ll diffA = a[i] - minA;
            ll diffB = b[i] - minB;
            cnt += max(diffA, diffB);  
        }

        cout << cnt << "\n";
    }

    return 0;
}
