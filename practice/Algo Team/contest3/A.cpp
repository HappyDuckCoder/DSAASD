#include <iostream>

using namespace std;

int main(){

    int time; cin >> time;
    while(time--){
        char a[5];
        for(int i = 0; i < 5; i++){
            cin >> a[i];
        }

        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < 5; i++){
            if(a[i] == 'A') cnt1++;
            else if(a[i] == 'B') cnt2++;
        }

        if(cnt1 > cnt2) cout << "A" << endl;
        else cout << "B" << endl;
    }


    return 0;
}