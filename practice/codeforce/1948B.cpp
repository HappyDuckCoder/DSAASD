#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int time; cin >> time;
    while(time--){
        int n; cin >> n;
        
        vector<int> a(n + 1);
        
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        bool check = true;
        int last = 0;
        
        for(int i = 1; i <= n; i++){
            if(a[i] < last){
                check = false;
                break;
            }
            if(a[i] < 10){
                last = a[i];
            } else {
                int t1 = a[i] / 10, t2 = a[i] % 10;
                if(t1 <= t2 && t1 >= last){
                    last = t2;
                } else {
                    last = a[i];
                }
            }
        }
        cout << (check ? "YES" : "NO") << '\n';
    }
}