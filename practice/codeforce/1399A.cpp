#include<iostream>
#include<vector>
#include<algorithm>

#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        bool check = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i + 1] - a[i] > 1){
                check = false;
                break;
            }
        }

        (check) ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}