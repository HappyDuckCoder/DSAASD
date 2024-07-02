#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map> 

#define vi vector<int>
#define vii vector<vi>

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

        vii dp(n, vi(n, 0));

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                dp[i][j] = a[i] + a[j];
            }
        }

        map<int, int> mp;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[dp[i][j]]++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
 
    }

    return 0;
}
