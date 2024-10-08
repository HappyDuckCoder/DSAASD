#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


int func(int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += i;
    }
    return sum;
}


int func2(int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            sum += i + j;
        }
    }
    return sum;
}

int func3(int a[], int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

int func4(int a[], int n, int key){
    sort(a, a + n); 
    return binary_search(a, a + n, key);
}


int algo1(string s){
    int n = stoi(s); 
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int algo2(string s){
    int sum = 0;
    int n = s.length(); 
    for(int i = 0; i < n; i++){
        sum += (s[i] - '0');
    }
    return sum;
}



int main(){

    return 0;
}