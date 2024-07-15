#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<climits> 

#define vi vector<int> 

using namespace std;


vi maxsubsumO3(vi &a, int n){
    
    int s = -1, e = -1;
    int max = INT_MIN;
    
    for(int i = 0; i < n; i++){
        for(int len = 1; len <= n - i; len++){
            int sum = 0;
            for(int j = 0; j < i + len; j++){
                sum += a[j];
            }
            if(sum > max){
                s = i;
                e = i + len - 1;
                max = sum;
            }
        }
    }
    
    vi res;
    for(int i = s; i <= e; i++)
        res.push_back(a[i]);
    
    return res;
}

vi maxsubsumO2(vi &a, int n){
    
    int max = INT_MIN;
    int s = -1, e = -1;
    
    vi b(n);
    b[0] = a[0];
    for(int i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = b[j] - b[i];
            if(sum > max){
                max = sum;
                s = i;
                e = j;
            }
        }
    }
    
    vi res;
    for(int i = s; i <= e; i++)
        res.push_back(a[i]);
    
    return res;
}

vi maxsubsumO1(vi &a, int n){
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

int findMaxWindow(vi &a, int n, int w){
    queue<int> qu;
    
    int sum = 0;
    
    for(int i = 0; i < w; i++){
        qu.push(a[i]); sum += a[i];
    }
    
    // qu.push(a[0]); sum += a[0];
    // qu.push(a[1]); sum += a[1];
    // qu.push(a[2]); sum += a[2]; 
    
    int maxVal = sum;
    
    cout << sum << " ";
    
    for(int i = w; i < n; i++){
        qu.push(a[i]); sum += a[i];
        sum -= qu.front(); qu.pop();
        
        cout << sum << " ";
        
        maxVal = max(maxVal, sum);
    }
    cout << endl;
    
    return maxVal;
}

void print(vi &a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    vi a = {1, -3, 5, 4, -2, 9, 7, -12, -15, 4, 4};
    int n = 11;
    
    vi res1 = maxsubsumO3(a, n);
    print(res1);
    
    return 0;
}