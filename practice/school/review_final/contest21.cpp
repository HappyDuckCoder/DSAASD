#include<iostream>
#include<vector>
#include<algorithm>

#define vi vector<int>

using namespace std;

const int __MAX__ = 1e6;

int ALGO_X(const vi &X, int n){
    int d = __MAX__;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(X[i] - X[j]) < d){
                d = abs(X[i] - X[j]);
            }
        }
    }
    return d;
}

int BETTER_X(const vi &X, int n){
    vi positive, negative; 
    for(int i = 0; i < n; i++){
        if(X[i] >= 0) positive.push_back(X[i]);
        else negative.push_back(X[i]);
    }
    
    int m = positive.size();
    int p = negative.size();

    if(m == 0) return negative[negative.size() - 2] - negative[negative.size() - 1];
    if(p == 0) return positive[1] - positive[0];

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());

    return positive[0] - negative[negative.size() - 1]; 
}

int searchArray(const vi &X, int n, int k){
    int l = 0, r = X.size() - 1;

    while(l <= r){
        int m = (l + r) / 2;

        if(X[m] == k) return m;
        
        if(X[l] <= X[m]){
            if(k >= X[l] && k < X[m]){
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if(k >= X[m] && k < X[r]){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    return -1;
}

void move(vi &X, int l, int r){
    if(l > r) return;

    int i = l, j = r;
    int pivot = X[(l + r) / 2]; 

    while(i <= j){
        while(X[i] % 2 == 0) i++;
        while(X[j] % 2 == 1) j--;
        if(i <= j){
            swap(X[i], X[j]);
            i++;
            j--;
        }
    }
    
    move(X, l, j);
    move(X, i, r);
}


int main(){

    

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi X(n); for(int i = 0; i < n; i++) cin >> X[i];
        int k; cin >> k;
        cout << searchArray(X, n, k) << "\n";
    }
    return 0;
}