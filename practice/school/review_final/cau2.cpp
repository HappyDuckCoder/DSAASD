#include<iostream>
#include<vector>
#include<string>

#define vi vector<int>

using namespace std;

const int PRIME = 311;
const int SIZE = 315;
// linear probing

vi HASH_TABLE(SIZE, 0);

void HASH(string s){
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += (i + 1) * (s[i] - '0');
    }
    // handle collision
    while(HASH_TABLE[sum] != 0){
        sum = (sum + 1) % PRIME;
    }
    HASH_TABLE[sum]++; 
}

int main(){

    string s; cin >> s;
    int n; cin >> n;
    vector<string> names(n);
    for(int i = 0; i < n; i++){
        cin >> names[i];
        HASH(names[i]);
    } 

    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += (i + 1) * (s[i] - '0');
    }

    if(HASH_TABLE[sum] != 0) cout << 1;
    else cout << 0;  

    // char a = 'h';
    // printf("%d", a);

    return 0;
}