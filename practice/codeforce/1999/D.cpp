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

        int n, m;
        n = s.size(), m = t.size();
        vector<int> dp(n, 0);

        int a = 0;
        
        for(int i = 0; i < n; i++){
            char x = t[a];
            if(s[i] == x){
                dp[i] += a; 
                a++;
            } else {
                continue;
            }
        }

        int max = dp[0];
        int ind = 0;
        for(int i = dp.size() - 1; i >= 0; i--){
            if(dp[i] >= max){
                max = dp[i];
                ind = i;
            }
        }

        int cnt = 0;
        for(int i = ind; i < n; i++){
            if(s[i] == '?')
                cnt++;
        }

        if(cnt == m){
            for(int i = 0; i < n; i++){
                if(s[i] == '?')
                    s[i] = a;
            }
            cout << s << endl;
            cout << "YES\n";
        }
    }

    return 0;
}
