#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;

int findmin(vector<ll> &a){
    int ind = 0;
    ll min = numeric_limits<ll>::max();
    for(int i = 0; i < a.size(); i++){
        if(a[i] < min){
            min = a[i];
            ind = i;
        }
    }
    return ind;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int l, r;
        cin >> l >> r;

        int n = r - l + 1;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
            a[i] = l + i; 

        int cnt = 0;

        while(true){
            int min_index = findmin(a);
            if (a[min_index] == 0) break;

            a[min_index] = floor(a[min_index] / 3);
            min_index = findmin(a);
            a[min_index] = a[min_index] * 3;
            cnt++;
        }

        for(int i = 0; i < n; i++){
            while(a[i]){
                a[i] = floor(a[i] / 3);
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
