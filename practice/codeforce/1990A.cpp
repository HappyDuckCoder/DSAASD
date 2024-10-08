#include<iostream>
#include<vector>
#include<algorithm>
#define vi vector<int> 
using namespace std;

void quicksort(vi &a, int left, int right){
    if(left >= right) return;

    int i = left, j = right;
    int pivot = a[(i + j) / 2];

    while(i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quicksort(a, left, j);
    quicksort(a, i, right);
}

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        quicksort(a, 0, n - 1);
        int cnt = 0;

        bool check = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i] != a[i + 1]){
                check = false;
                break;
            } else cnt++; 
        }

        if(cnt % 2 == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
