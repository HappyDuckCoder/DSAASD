#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<climits> 

#define vi vector<int> 

using namespace std;

vi HASH_TABLE(20, 0);
int sizeHash = 20;

void Linear_Hashing(int x){
    int i = x % sizeHash;
    while(HASH_TABLE[i] != 0){
        i = (i + 1) % sizeHash;
    }
    HASH_TABLE[i] = x;
}

void Quadaric_Hashing(int x){
    int i = x % sizeHash;
    int j = 0;
    while(HASH_TABLE[i] != 0){
        i = (i + j * j) % sizeHash;
        j++;
    }
    HASH_TABLE[i] = x;
}


//Hash2(x) = PRIME - (x % PRIME)
int Hashing2(int x){
    int PRIME = 19;
    int i = x % PRIME;
    return PRIME - i;
}

void Double_Hashing(int x){
    int i = x % sizeHash;
    int j = 0;
    while(HASH_TABLE[i] != 0){
        i = (i + j * Hashing2(x)) % sizeHash;
        j++;
    }
    HASH_TABLE[i] = x;
}

int main(){
    vi a = {1, 8, 10, 2, 15, 23, 5, 6, 100, -23, 333, 2802};
    int n = a.size();
    
    for(int i = 0; i < n; i++){
        Double_Hashing(a[i]);
    }
    
    for(int i = 0; i < sizeHash; i++){
        cout << HASH_TABLE[i] << " ";
    }
    
    return 0;
}