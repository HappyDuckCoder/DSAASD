#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int findmin(vector<ll> &a){
    int ind = -1, min = a[0];
    for(int i = 0; i < a.size(); i++){
        if(i == 1) continue;
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

        int n = r - l;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
            a[i] = l + i; 
        
        // for(int i = 0; i < n; i++)
        //     cout << a[i] << " ";
        // cout << endl;

        int cnt = 0;

        while(a[1]){
            a[1] = floor(a[1] / 3);
            if(a.size() == 2){
                a[0] = a[0] * 3;
                cnt++;
            } else {
                int t = findmin(a);
                a[t] = a[t] * 3;
                // cout << a[1] << " " << a[t] << "\n"; 
                cnt++;
            }
        }

        for(int i = 0; i < n; i++){
            while(a[i]){
                a[i] = floor(a[i] / 3);
                cnt++;
                // cout << a[i] << " ";
            }
            // cout << endl;
        }

        cout << cnt << "\n";
    }

    return 0;
}
