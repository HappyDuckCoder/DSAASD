#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<climits> 
#include<algorithm>

#define vi vector<int> 

using namespace std;

int binarySearch(vi &a, int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x) return m;
        else if(a[m] > x) r = m - 1;
        else l = m + 1;
    }
    
    return -1;
}

int lowerbound(vi &a, int n, double x){
    if(a[0] > x) return -1;
    
    int l = 0, r = n - 1;
    while(l < r){
        int m = (l + r) / 2 + 1;
        if(a[m] > x) r = m - 1;
        else l = m;
    }
    
    return l;
}

int upperbound(vi &a, int n, double x){
    if(a[n - 1] < x) return -1;
    
    int l = 0, r = n - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(a[m] >= x) r = m;
        else l = m + 1;
    }
    
    return l;
}

void heapify(vi &a, int n, int i, vi &idx){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && a[largest] < a[left])
        largest = left;
    if(right < n && a[largest] < a[right])
        largest = right;
        
    if(largest != i){
        swap(a[largest], a[i]);
        swap(idx[largest], idx[i]);
        heapify(a, n, largest, idx);
    }
}

void heapSort(vi &a, int n, vi &idx){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i, idx);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        swap(idx[0], idx[i]);
        heapify(a, i, 0, idx);
    }
}

int binarySearch2(vi &a, int n, int x, vi &idx){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x) return idx[m];
        else if(a[m] > x) r = m - 1;
        else l = m + 1;
    }
    
    return -1;
}

int main(){
    
    vi a = {1, 8, 7, 0, 4, 3, 5, 2, 9, 6};
    vi idx = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = a.size();
    // sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    heapSort(a, n, idx);
    
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << idx[i] << " ";
    cout << endl;
    
    // cout << binarySearch(a, n, 6);
    // cout << lowerbound(a, n, -10);
    // cout << upperbound(a, n, 3.5);
    cout << binarySearch2(a, n, 7, idx);
    
    return 0;
}