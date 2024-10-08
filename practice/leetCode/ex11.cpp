#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    void SORT(vector<int> &a, vector<int> &index, int l, int r){
        if(l >= r) return;

        int i = l, j = r;
        int x = a[(l + r) / 2];

        while(i <= j){
            while(a[i] < x) i++;
            while(a[j] > x) j--;
            if(i <= j){
                swap(a[i], a[j]);
                swap(index[i], index[j]);
                i++;
                j--;
            }
        }

        SORT(a, index, l, j);
        SORT(a, index, i, r);
    }

    int maxArea(vector<int>& a) {
        int res = 0;
        int n = a.size();
        
        vector<int> index(n);
        for(int i = 0; i < n; i++) index[i] = i;
        SORT(a, index, 0, n - 1);

        for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        for(int i = 0; i < n; i++) cout << index[i] << " "; cout << endl;


        for(int i = n - 1; i > 0; i--){
            int h = min(a[i], a[i - 1]);
            cout << h << ": height\n";
            int w = abs(index[i] - index[i - 1]);
            cout << w << ": width\n";
            res = max(res, h * w);
        }   

        return res;
    }
};

int main(){
    Solution s;
    vector<int> a = {1, 0, 0, 0, 0, 0, 0, 2, 2};
    int t = s.maxArea(a);

    cout << t;

    return 0;
}