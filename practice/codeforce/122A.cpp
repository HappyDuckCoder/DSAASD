#include<iostream>
#include<string>

using namespace std;

string lucky[100]; 
int index = 0;

void createLucky(string s, int i){
    if(s.length() > 0) lucky[index++] = s;
    if(s.length() == 4) return;
    
    createLucky(s + '4', i + 1);
    createLucky(s + '7', i + 1);
}

int main(){
    
    createLucky("", 0);
    // for(int i = 0; i < index; i++){
    //     cout << lucky[i];
    //     cout << endl;
    // }
    
    int n; cin >> n;
    
    bool check = false;
    
    for(int i = 0; i < index; i++){
        int t = stoi(lucky[i]);
        if(n % t == 0){
            check = true;
            break;
            // n = n / t;  
        } 
        // cout << "n: " << n << "\n";
        // cout << "t: " << t << "\n";
    }
    
    // (n == 1) ? cout << "YES\n" : cout << "NO\n";
    (check) ? cout << "YES\n" : cout << "NO\n";
    
    return 0;
}