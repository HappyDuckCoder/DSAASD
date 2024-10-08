#include<iostream>
using namespace std;

int n = 10;
int a[10] = {2, 3, 6, 7, 10, 4, 12, 57, 83, 46};

void print(int a[], int n){
    for(int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl; 
}

void quicksort(int a[], int l, int r){
    if(l >= r) return;

    int i = l, j = r;
    
    cout << "choose pivot x = ";
    int x = a[(l + r) / 2];
    cout << x << endl;
    
    while(i <= j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j){
            
            cout << "swap " << a[i] << " " << a[j] << "\n";

            swap(a[i], a[j]);
            print(a, n);
            i++;
            j--;
        }
    }

    quicksort(a, l, j);
    quicksort(a, i, r);
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // find the largest step
    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    // swap the max to the root and continue modified its children
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    cout << "step 1: build max heap \n";

    for(int i = n / 2 - 1; i >= 0; i--){
        cout << "heapifying " << a[i] << "\n";
        heapify(a, n, i);
        print(a, n);
    }

    cout << "step 2: swap the max element to the end and continue heap sort \n";

    for(int i = n - 1; i >= 0; i--){
        cout << "swap the max element to the end \n";
        swap(a[0], a[i]);
        print(a, n);
        heapify(a, i, 0);
    }
}

int main(){
    cout << "original array: ";
    print(a, n);
    heapSort(a, n);
    return 0;
}