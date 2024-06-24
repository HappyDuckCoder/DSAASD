#include <iostream>
#include <vector>
#include <climits>
#define vi std::vector<int>

using namespace std;

vi MaxSubArrayWithO3(vi &a, int n){
    int maxSum = INT_MIN;
    int start = 0, end = 0;

    for(int i = 0; i < n; i++){
        for(int len = 1; len <= n - i; len++){
            int sum = 0;
            for(int j = i; j < i + len; j++){
                sum += a[j];
            }
            if(sum > maxSum){
                maxSum = sum;
                start = i;
                end = i + len - 1;
            }
        }
    }

    vi res;
    for(int i = start; i <= end; i++) res.push_back(a[i]);
    
    return res;
}

vi MaxSubArrayWithO2(vi &a, int n){
    int maxSum = INT_MIN;
    int start = 0, end = 0;

    vi b(n + 1, 0);
    b[0] = 0;
    for(int i = 1; i <= n; i++){
        b[i] = a[i - 1] + b[i - 1];
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = b[j + 1] - b[i];
            if(sum > maxSum){
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }

    vi res;
    for(int i = start; i <= end; i++) res.push_back(a[i]);
    
    return res;
}

vi MaxSubArrayWithO1(vi &a, int n){
    int sum1 = 0;
    int sum2 = INT_MIN;
    int start = 0, end = 0, tempStart = 0;

    for(int i = 0; i < n; i++){
        sum1 += a[i];

        if(sum2 < sum1){
            sum2 = sum1;
            start = tempStart;
            end = i;
        }

        if(sum1 < 0){
            sum1 = 0;
            tempStart = i + 1;
        }
    }

    vi res;
    for(int i = start; i <= end; i++) res.push_back(a[i]);
    
    return res;
}

void print(vi &a){
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;  
}

int main(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vi res1 = MaxSubArrayWithO1(a, n);
    vi res2 = MaxSubArrayWithO2(a, n);
    vi res3 = MaxSubArrayWithO3(a, n);
    
    print(res1);
    print(res2);
    print(res3);

    return 0;
}
