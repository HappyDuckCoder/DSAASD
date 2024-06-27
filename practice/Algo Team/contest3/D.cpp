#include <iostream>
#include <vector>

using namespace std;

int main() {
    int time;
    cin >> time;
    while(time--){
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int saveIndex1 = -1, saveIndex2 = -1;
        bool check1 = false;

        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(a[i][j] == '1') {
                    saveIndex1 = i;
                    saveIndex2 = j;
                    check1 = true;
                    break;
                }
            }
            if(check1) break;
        }

        int saveIndex3 = -1, saveIndex4 = -1;
        bool check2 = false;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == '1') {
                    saveIndex3 = i;
                    saveIndex4 = j;
                    check2 = true;
                    break;
                }
            }
            if(check2) break;
        }

        char c = a[saveIndex1][saveIndex4];
        char d = a[saveIndex3][saveIndex2];

        if(c == '1' && d == '1') {
            cout << "SQUARE" << endl;
        } else {
            cout << "TRIANGLE" << endl;
        }
    }

    return 0;
}
