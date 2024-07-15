#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<climits> 

#define vi vector<int> 

using namespace std;

void selectionSort(vi &a, int n);
void insertionSort(vi &a, int n);
void bubbleSort(vi &a, int n);
void interchangeSort(vi &a, int n);
void binaryinsertionSort(vi &a, int n);
void shakerSort(vi &a, int n);
void quickSort(vi &a, int l, int r);
void heapSort(vi &a, int n);
void mergeSort(vi &a, int l, int r);
void radixSort(vi &a, int n);
void countingSort(vi &a, int n);

int lowerbound(vi &a, int left, int right, int x){
    while(left < right){
        int mid = (left + right) / 2;
        if(a[mid] < x) left = mid + 1;
        else right = mid;
    }
    return left;
}

void heapify(vi &a, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && a[left] > a[largest])
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;
    
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void merge(vi &a, int l, int m, int r){
    int n_left = m - l + 1;
    int n_right = r - m;
    vi left(n_left), right(n_right);
    
    for(int i = 0; i < n_left; i++)
        left[i] = a[l + i];
    for(int i = 0; i < n_right; i++)
        right[i] = a[m + 1 + i];
        
    int i_left = 0, i_right = 0;
    int index = l;
    
    while(i_left < n_left && i_right < n_right){
        if(left[i_left] <= right[i_right]){
            a[index] = left[i_left];
            i_left++;
        } else {
            a[index] = right[i_right];
            i_right++;
        } 
        index++;
    }
    
    while(i_left < n_left){
        a[index] = left[i_left];
        index++;
        i_left++;
    }
    
    while(i_right < n_right){
        a[index] = right[i_right];
        index++;
        i_right++;
    }
}

void print(vi &a, int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    vi a = {1, -3, 5, 4, -2, 9, 7, -12, -15, 4, 4};
    int n = 11;
    
    // selectionSort(a, n);
    // insertionSort(a, n);
    // bubbleSort(a, n);
    // interchangeSort(a, n);
    // binaryinsertionSort(a, n);
    // shakerSort(a, n);
    // quickSort(a, 0, n - 1);
    // heapSort(a, n);
    mergeSort(a, 0, n - 1);
    print(a, n);
    
    return 0;
}

void selectionSort(vi &a, int n){
    for(int i = 0; i < n; i++){
        int pos = i;
        
        for(int j = i + 1; j < n; j++){
            if(a[pos] > a[j])
                pos = j;
        }
        
        swap(a[i], a[pos]);
    }
}

void insertionSort(vi &a, int n){
    for(int i = 1; i < n; i++){
        int pos = i - 1;
        int v = a[i];
        while(pos >= 0 && a[pos] > v){
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = v;
    }
}

void bubbleSort(vi &a, int n){
    for(int i = 0; i < n; i++)
        for(int j = n - 1; j > i; j--)
            if(a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
}

void interchangeSort(vi &a, int n){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                swap(a[i], a[j]);
}

void binaryinsertionSort(vi &a, int n){
    for(int i = 1; i < n; i++) {
        int v = a[i];
        int pos = lowerbound(a, 0, i, v);
        
        for(int j = i; j > pos; j--)
            a[j] = a[j - 1];

        a[pos] = v;
    }
}

void shakerSort(vi &a, int n){
    int top = 0, bottom = n - 1, save = n - 1;
    
    while(top < bottom){
        for(int i = bottom; i > top; i--){
            if(a[i - 1] > a[i]){
                swap(a[i], a[i - 1]);
                save = i;
            }
        }
        top = save;
        
        for(int i = top; i < bottom; i++){
            if(a[i + 1] < a[i]){
                swap(a[i], a[i + 1]);
                save = i + 1;
            }
        }
        bottom = save;
    }
}

void quickSort(vi &a, int l, int r){
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
    
    if(l <= j) quickSort(a, l, j);
    if(i <= r) quickSort(a, i, r);
}

void heapSort(vi &a, int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void mergeSort(vi &a, int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
// void radixSort()
// void countingSort()