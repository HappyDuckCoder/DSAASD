#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int time; cin >> time;
  while(time--){
    int m; cin >> m;
    
    vi a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    
    vi b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    vi pref(m + 1);
    for(int i = 0; i < m; i++) pref[i + 1] = pref[i] + b[i];

    vi suf(m + 1);
    for(int i = m - 1; i >= 0; i--) suf[i] = suf[i + 1] + a[i];

    int ans = (int) 1e9;
    for(int i = 0; i < m; i++) ans = min(ans, max(pref[i], suf[i + 1]));

    cout << ans << '\n';
  }
  return 0;
}
