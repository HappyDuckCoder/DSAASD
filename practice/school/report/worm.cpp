#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &prefixSums, int x){
    int l = 0, r = prefixSums.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(prefixSums[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    vector<int> prefixSums(n + 1, 0);
    for(int i = 1; i <= n; i++) 
        prefixSums[i] = prefixSums[i - 1] + a[i - 1];

    int m; cin >> m;
    while(m--){
        int x; cin >> x;
        int pileIndex = binarySearch(prefixSums, x);
        cout << pileIndex << endl;
    }

    return 0;
}
