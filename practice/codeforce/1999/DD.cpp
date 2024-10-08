#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s; cin >> s; 
        string t; cin >> t; 

        int n = s.size(), m = t.size();
        vector<int> dp(n + 1, 0);

        int j = 0;
        for(int i = 0; i < n; i++){
            if(j < m && (s[i] == t[j] || s[i] == '?')){
                dp[i + 1] = dp[i] + 1;
                j++;
            } else {
                dp[i + 1] = dp[i];
            }
        }

        if(dp[n] < m){
            cout << "NO\n";
        } else {
            j = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '?'){
                    if(j < m && dp[i + 1] == j + 1){
                        s[i] = t[j];
                        j++;
                    } else {
                        s[i] = 'a';
                    }
                }else if(s[i] == t[j]){
                    j++;
                }
            }
            cout << "YES\n" << s << endl;
        }
    }

    return 0;
}
