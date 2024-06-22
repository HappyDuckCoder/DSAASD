#include <iostream>
using namespace std;

const int PRIME = 7;
int hashTable[20] = {0};
int sizeHashTable = 20;

void linearHashing(int x, int n){
    int index = x % n;
    while(hashTable[index] != 0){
        index = (index + 1) % n;
    }
    hashTable[index] = x;
}

void doubleHashing(int x, int n){
    int index = x % n;
    int i = 0;
    while(hashTable[index] != 0){
        int doubleIndex = PRIME - (x % PRIME);
        index = (index + doubleIndex * i) % n;
        i++;
    }
    hashTable[index] = x;
}

void quadraticHashing(int x, int n){
    int index = x % n;
    int i = 0;
    while(hashTable[index] != 0){
        index = (index + i * i) % n;
        i++;
    }
    hashTable[index] = x;
}

void printHashTable(){
    for(int i = 0; i < sizeHashTable; i++){
        cout << hashTable[i] << " ";
    }
    cout << endl;
}

void fill(int a[], int n, int value){
    for(int i = 0; i < n; i++){
        a[i] = value;
    }
}

int main(){
    int a[15] = {172, 736, 415, 321, 657, 5444, 8, 90, 23, 35, 7, 9, 11, 4, 777};
    int n = 15;

    cout << "Linear Hashing:" << endl;
    for(int i = 0; i < n; i++){
        linearHashing(a[i], sizeHashTable);
    }
    printHashTable();

    fill(hashTable, sizeHashTable, 0);

    cout << "Double Hashing:" << endl;
    for(int i = 0; i < n; i++){
        doubleHashing(a[i], sizeHashTable);
    }
    printHashTable();

    fill(hashTable, sizeHashTable, 0);

    cout << "Quadratic Hashing:" << endl;
    for(int i = 0; i < n; i++){
        quadraticHashing(a[i], sizeHashTable);
    }
    printHashTable();

    return 0;
}
