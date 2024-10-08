#include<iostream>
using namespace std;

//=======================order search=========================//

void sort(int a[], int n, int index[]){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j]){
                swap(a[i], a[j]);
                swap(index[i], index[j]);
            }
}

int binarySearch(int a[], int n, int key){
    int left = 0, right = n - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] < key) left = mid + 1;
        else if(a[mid] > key) right = mid - 1;
        else return mid;
    }

    return -1;
}

int binarySearchRecursive(int a[], int left, int right, int key){
    if(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] < key) return binarySearchRecursive(a, mid + 1, right, key);
        else if(a[mid] > key) return binarySearchRecursive(a, left, mid - 1, key);
        else return mid;
    }

    return -1;
}

int upperBound(int a[], int n, int key){
    if(a[n - 1] < key) return n;

    int left = 0, right = n - 1;
    
    while(left < right){
        int mid = (left + right) / 2;
        if(a[mid] < key) left = mid + 1;
        else right = mid;
    }

    return left;
}

int lowerBound(int a[], int n, int key){
    if(a[0] > key) return 0;

    int left = 0, right = n - 1;
    
    while(left < right){
        int mid = (left + right) / 2 + 1;
        if(a[mid] > key) right = mid - 1;
        else left = mid;
    }

    return left;
}

//==================unordered search=========================


int binarySearchWithUnordered(int a[], int n, int index[], int key){
    int left = 0, right = n - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] < key) left = mid + 1;
        else if(a[mid] > key) right = mid - 1;
        else return index[mid];
    }

    return -1;
}

int binarySearchWithUnorderedRecursive(int a[], int left, int right, int index[], int key){
    if(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] < key) return binarySearchWithUnorderedRecursive(a, mid + 1, right, index, key);
        else if(a[mid] > key) return binarySearchWithUnorderedRecursive(a, left, mid - 1, index, key);
        else return index[mid];
    }

    return -1;
}

//======================support function======================//
void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[10] = {20, 14, 8, 6, 12, 10, 2, 16, 18, 4};
    int index[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;

    print(a, n); //unordered
    print(index, n);

    int key = 13; 

    sort(a, n, index); 
    print(a, n); //ordered

    // cout << upperBound(a, n, key) << endl;
    // cout << lowerBound(a, n, key) << endl;

    // cout << binarySearchWithUnordered(a, n, index, key);
    // cout << binarySearchWithUnorderedRecursive(a, 0, n - 1, index, key);
    
    // cout << binarySearch(a, n, key) << endl;
    // cout << binarySearchRecursive(a, 0, n - 1, key) << endl;

    return 0;
}