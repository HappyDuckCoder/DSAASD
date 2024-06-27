#include <iostream>
#include <string>


using namespace std;

int main(){

    // int time; cin >> time;
    // while(time--){
        string a, b;
        cin >> a >> b; 

        if(a.length() != b.length()){
            cout << "NO" << endl;
        } else {

            int n = a.length();

            if(n == 1){
                if(a[0] != b[0]){
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            } else {
                bool check = true;

                for(int i = 0; i < n; i++){
                    if(a[i] != b[n - 1 - i]){
                        check = false;
                        break;
                    }
                }    

                (check) ? cout << "YES": cout << "NO";

                cout << endl;
            }            
        }
    // }


    return 0;
}