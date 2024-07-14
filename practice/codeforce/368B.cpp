#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define vi vector<int> 

// int DistinctNumberFromX(vi &a, int n, int x){
//     int size = n - x + 1;
//     vi tmp(size + 1); 
//     for(int i = 1; i <= size; i++){
//         tmp[i] = a[x + i - 1];
//     }
//     int cnt = 0; 
//     vi hash(100001, 0);
//     for(int i = 1; i <= size; i++)
//         hash[tmp[i]]++;
//     for(int i = 1; i <= 100001; i++){
//         if(hash[i] != 0)
//             cnt++;
//     }
//     return cnt;
// }

int main(){
    int n, m; 
    cin >> n >> m;
    
    vi a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    set<int> s;
    vi dp(n + 1, 0); 
    
    for(int i = 1; i <= n; i++){
        s.insert(a[n + 1- i]);
        dp[n - i + 1] = s.size();
    }
    
    // vi dp(n + 1, 0);
    // for(int i = 1; i <= n; i++){
    //     dp[i] = DistinctNumberFromX(a, n, i);
    // }
    
    for(int i = 1; i <= m; i++){
        cout << dp[b[i]] << endl;
    }
    
    return 0;
}
