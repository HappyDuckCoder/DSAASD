#include<iostream>
#include<vector>

using namespace std;

bool linearSearch(int a[], int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key){
            cout << "founded!";
            return true;
        }
    }    
}

const int FLAG = -100;
bool linearSearchWithSentinel(vector<int> &a, int n, int key){
    int flag = FLAG;
    a.push_back(flag); //let the sentinel in the end of the array

    for(int i = 0; i < n; i++){
        if(a[i] == key){
            flag = key;
            cout << "founded";
            break;
        }
        if(a[i] == flag){
            cout << "we reach the end of the array and the key can find from nowhere";
        }
    }    

    if(flag == key) return true;
    if(flag == FLAG) return false;
}

bool binarySearch(int a[], int n, int key){
    int l = 0, r = n - 1;

    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == key){
            cout << "founded";
            return true;
        } else if(a[m] > key) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return false;
}

int main(){

    return 0;
}