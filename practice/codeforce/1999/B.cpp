#include<iostream>
using namespace std;

int main() {
    int t; 
    cin >> t; 
    while(t--){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int cnt = 0;

        int A = 0;
        int B = 0;

        A = (a1 > b1) + (a2 > b2);
        B = (b1 > a1) + (b2 > a2);
        if(A > B) cnt++;

        A = (a1 > b2) + (a2 > b1);
        B = (b2 > a1) + (b1 > a2);
        if(A > B) cnt++;

        A = (a2 > b1) + (a1 > b2);
        B = (b1 > a2) + (b2 > a1);
        if(A > B) cnt++;

        A = (a2 > b2) + (a1 > b1);
        B = (b2 > a2) + (b1 > a1);
        if(A > B) cnt++;

        cout << cnt << "\n";
    }

    return 0;
}
