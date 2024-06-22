#include<iostream>
#include<vector>
#define vi vector<int>
#define vii vector<vi>

using namespace std;
int main(){
    int n; cin >> n;
    int S; cin >> S;
    vi a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }    

    vii dp(n + 1, vector<int>(S + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= S; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
        }
    }

    cout << dp[n][S] << endl;

    return 0;
}