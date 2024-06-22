#include<iostream>
#include<vector> 
#define vi vector<int>

using namespace std;
int main(){
    int n; cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vi dp(n + 1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, dp[i]);
    cout << res << endl;

    return 0;
}