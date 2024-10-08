#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        ll s, m;
        cin >> n >> s >> m;

        vector<pair<ll, ll>> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }

        bool check = false;

        if(a[0].first >= s){
            check = true;
        }

        for(int i = 1; i < n; i++){
            if(a[i].first - a[i - 1].second >= s){
                check = true;
                break;
            }
        }

        if(m - a[n - 1].second >= s){
            check = true;
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}
