#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<pair<string, int>> &a, int l, int r){
    if(l >= r) return;

    int i = l, j = r;
    int x = a[(l + r) / 2].second;

    while(i <= j){
        while(a[i].second < x) i++;
        while(a[j].second > x) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quicksort(a, l, j);
    quicksort(a, i, r);
}

int main(){

    int n; cout << "input n: "; cin >> n;
    vector<pair<string, int>> a; 
    for(int i = 0; i < n; i++){
        pair<string, int> tmp;
        cout << "nhap thong tin player thu " << i + 1 << ": ";
        cin >> tmp.first >> tmp.second;
        a.push_back(tmp);
    }
    quicksort(a, 0, n - 1);
    cout << "top 5: \n"; 
    for(int i = 0; i < 5; i++){
        cout << "top " << i + 1 << ": " << a[i].first << " - " << a[i].second << "\n";
    }

    return 0;
}