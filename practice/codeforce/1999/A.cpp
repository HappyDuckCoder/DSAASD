#include<iostream>
using namespace std;
int main(){

    int t; cin >> t; 
    while(t--){
        int a; cin >> a;
        int x = a % 10;
        int y = a / 10; 
        cout << x + y << "\n";
    }

    return 0;
}