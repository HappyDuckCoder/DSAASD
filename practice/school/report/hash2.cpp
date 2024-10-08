#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){

    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<string, int>> HASH(1001, {"", 0}); 

    for(int i = 0; i < n; i++){

        string s = a[i];
        bool check = false;

        for(int j = 0; j < 1001; j++){
            if(HASH[j].first == s){
                check = true;

                string tmp = HASH[j].first + to_string(HASH[j].second);
                cout << tmp << "\n";
                HASH[j].second++;
            }
        }

        if(!check){
            cout << "OK\n";
            for(int j = 0; j < 1001; j++){
                if(HASH[j].first == ""){
                    HASH[j].first = s;
                    HASH[j].second++;
                    break;
                }
            }
        }
    }

    return 0;
}