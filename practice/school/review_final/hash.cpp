#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>

using namespace std;

const int SIZE = 100; 
int tableHash[SIZE] = {0};

const int stopCondition = 15;

void linearHashing(int key){
    // this method CAN NOT appear the situation with infinity loop
    int index = key % SIZE; 
    int cnt = 0;
    while(tableHash[index] != 0){
        index = (index + 1) % SIZE;
        cnt++;
        if(cnt == SIZE){
            cout << "can not handle collision because the numbers reach the max size" << endl;
            return; // return if can not add any number
        }
    }
    tableHash[index] = key;
}

void quadraticHashing(int key){
    // this method CAN appear the situation with infinity loop
    int index = key % SIZE; 
    int i = 0;
    int cnt = 0;
    while(tableHash[index] != 0){
        index = (index + i * i) % SIZE;
        i++;
        cnt++; 
        if(i == stopCondition){
            cout << "infinity loop this key will be replaced by " << tableHash[index] << endl; 
            break;
        }
        if(cnt == SIZE){
            cout << "can not handle collision because the numbers reach the max size";
            return; // return if can not add any number
        }
    }
    tableHash[index] = key;
}

int supportHashing(int key, int PRIME){
    return PRIME - (key % PRIME);
}

void doubleHashing(int key, int PRIME){
    int index = key % SIZE; 
    int i = 0;
    int cnt = 0;
    while(tableHash[index] != 0){
        index = (index + i * supportHashing(key, PRIME)) % SIZE;
        i++;
        cnt++; 
        if(i == stopCondition){
            cout << "infinity loop this key will be replaced by " << tableHash[index] << endl; 
            break;
        }
        if(cnt == SIZE){
            cout << "can not handle collision because the numbers reach the max size";
            return; // return if can not add any number
        }
    }
    tableHash[index] = key;
}

void restart(){
    for(int i = 0; i < SIZE; i++){
        tableHash[i] = 0;
    }
}

void printHash(){
    for(int i = 0; i < SIZE; i++){
        cout << tableHash[i] << " ";
    }
    cout << endl;
}

int search(int number){
    for(int i = 0; i < SIZE; i++){
        if(tableHash[i] == number){
            cout << "found at numbers " << i;
            return i;
        }
    }
    return -1;
}

void chainingCreateTable(int a[], int N, int NUMBER){
    int col = 0;
    int row = SIZE;
    // create chaining hash table with N rows and that row do not have any value
    vector<vector<int>> chainingTable (row, vector<int> (col)); 
    for(int i = 0; i < N; i++){
        int index = a[i] % SIZE;
        chainingTable[index].push_back(a[i]);
    } 

    int searching = -1;

    for(int i = 0; i < SIZE; i++){
        cout << "box " << i << ": ";
        if(chainingTable[i].size() == 0){
            cout << "this box do not have any numbers at box " << i << endl;
        }
        else {
            for(int j = 0; j < chainingTable[i].size(); j++){
                cout << chainingTable[i][j] << " "; 
                if(NUMBER == chainingTable[i][j]){
                    searching = chainingTable[i][j];
                }
            }
            cout << endl;
        }
    }

    if(searching != -1) cout << "finded at box " << searching;
    else cout << "this number do not stay in this array\n";
}

int main(){

    int N = SIZE; // hash SIZE = 100 numbers into hashtable
    cin >> N; 

    int a[N]; 

    int PRIME = 7; // choose PRIME = 97 < 100 for double hashing

    int NUMBER = 42;
    
    for(int i = 0; i < N; i++) a[i] = rand() % 100 + 1; // generate 100 random numbers in [1, 100]
    cout << "original array \n";
    for(int i = 0; i < N; i++) cout << a[i] << " "; 
    cout << endl << endl; 

    cout << "linear handling \n";
    for(int i = 0; i < N; i++) linearHashing(a[i]); printHash(); 
    cout << "search " << NUMBER << ": " << search(NUMBER);
    cout << endl << endl; restart(); 

    cout << "quadratic handling \n";
    for(int i = 0; i < N; i++) quadraticHashing(a[i]); printHash(); 
    cout << "search " << NUMBER << ": " << search(NUMBER);
    cout << endl << endl;  restart(); 
    cout << "double handling \n";

    for(int i = 0; i < N; i++) doubleHashing(a[i], PRIME); printHash();
    cout << "search " << NUMBER << ": " << search(NUMBER);
    cout << endl << endl;  restart(); 

    // for chaining handling, I design it in other function 
    chainingCreateTable(a, N, NUMBER);

    return 0;
}