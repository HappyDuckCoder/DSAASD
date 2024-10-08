#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>

using namespace std;

const int SIZE = 105;
const int PRIME = 7;

vector<int> HASH_ADDRESSING(SIZE, 0);
vector<vector<int>> HASH_CHAINING(SIZE, vector<int> ());

void LinearHashing(int x){
    int index = x % SIZE;
    while(HASH_ADDRESSING[index] != 0){
        index = (index + 1) % SIZE;
    }
    HASH_ADDRESSING[index] = x;
}

void QuadraticHashing(int x){
    int index = x % SIZE;
    int i = 0;
    while(HASH_ADDRESSING[index] != 0){
        index = (index + i * i) % SIZE;
        i++;
    }
    HASH_ADDRESSING[index] = x;
}

void DoubleHashing(int x){
    int index = x % SIZE;
    int i = 0;
    while(HASH_ADDRESSING[index] != 0){
        index = (index + i * (PRIME - (x % PRIME))) % SIZE;
        i++;
    }
    HASH_ADDRESSING[index] = x;
}

void ChainingHashish(int x){
    int index = x % SIZE;
    HASH_CHAINING[index].push_back(x);
}

int main(){
    srand(time(NULL));

    int n = 20;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = rand() % 100 + 1;

    while(true){
        cout << "===================================\n";
        cout << "1. Linear Hashing \n";
        cout << "2. Quadratic Hashing \n";
        cout << "3. Double Hashing \n";
        cout << "4. Chaining Hashing \n\n";

        cout << "Choose your option: \n";
        int opt; cin >> opt;
        cout << "===================================\n";

        while(opt < 1 || opt > 4){
            cout << "Input 1 - 4: ";
            cin >> opt;
        }

        if(opt == 1){
            for(int i = 0; i < n; i++){
                LinearHashing(a[i]);
            }
            for(int i = 0; i < SIZE; i++){
                cout << HASH_ADDRESSING[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < SIZE; i++){
                HASH_ADDRESSING[i] = 0;
            }
        } else if(opt == 2){
            for(int i = 0; i < n; i++){
                QuadraticHashing(a[i]);
            }
            for(int i = 0; i < SIZE; i++){
                cout << HASH_ADDRESSING[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < SIZE; i++){
                HASH_ADDRESSING[i] = 0;
            }
        } else if(opt == 3){
            for(int i = 0; i < n; i++){
                DoubleHashing(a[i]);
            }
            for(int i = 0; i < SIZE; i++){
                cout << HASH_ADDRESSING[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < SIZE; i++){
                HASH_ADDRESSING[i] = 0;
            }
        } else if(opt == 4){
            for(int i = 0; i < n; i++){
                ChainingHashish(a[i]);
            }
            for(auto i : HASH_CHAINING){
                if(i.size() == 0) continue;
                else{
                    for(auto j : i){
                        cout << j << " ";
                    }
                    cout << endl;
                }
            }
        }
        cout << "===================================\n";
    }

    return 0;
}