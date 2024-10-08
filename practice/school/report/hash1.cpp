#include<iostream>
using namespace std;
int main(){

    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

    int HASH[1001] = {0};
    for(int i = 0; i < n; i++) HASH[a[i]]++;

    for(int i = 0; i < 1001; i++){
        if(HASH[i] != 0){
            cout << i << " appear " << HASH[i] << " times \n";
        }
    }

    return 0;
}