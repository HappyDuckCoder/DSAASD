#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vi dp(n - k + 1); 
    for(int i = 0; i < k; i++)
        dp[0] += a[i];
        
    for(int i = 1; i < n - k + 1; i++){
        dp[i] = dp[i - 1] + a[i + k - 1] - a[i - 1];
    }
    
    // for(int i = 0; i < n - k + 1; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    
    int minVal = dp[0];
    int save = 0;
    
    for(int i = 1; i < dp.size(); i++){ 
        if(minVal > dp[i]){
            minVal = dp[i];
            save = i;
        }
    }
    
    cout << save + 1 << "\n";
    
    return 0;
}
