#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

#define vi vector<int>

using namespace std;

int n = 10;
vi a(n);
void init(){for(int i = 0; i < n; i++) a[i] = rand() % 100 + 1;}
void print(){for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;}

void selectionSort(){
    for(int i = 0; i < n; i++){
        int pos = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[pos]){
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
}

void insertionSort(){
    for(int i = 1; i < n; i++){
        int v = a[i];
        int pos = i - 1;
        while(a[pos] > v && pos > 0){
            a[pos + 1] = a[pos];
            pos--;
        }
        swap(v, a[pos + 1]);
    }
}

void heapify(int i, int size){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(a[largest] < a[l] && l < size) largest = l;
    if(a[largest] < a[r] && r < size) largest = r;

    if(largest != i){
        swap(a[largest], a[i]);
        heapify(largest, size);
    }
}

void heapSort(){
    for(int i = n / 2 + 1; i >= 0; i--) heapify(i, n);
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(0, i);
    }
}

void quickSort(int l, int r){
    if(l > r) return;
    
    int i = l, j = r;
    int x = a[(l + r) / 2];

    while(i <= j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quickSort(l, j);
    quickSort(i, r);
}

void heapSort(){
    // copy code
}

// code tree 
void insertAVL();
void deleteAVL();
// copy completed, full, perfect


int main(){
    srand(time(0));
    init();
    print();
    quickSort(0, n - 1);
    print();
    return 0;
}