#include<iostream>
#include<string>

using namespace std;

bool ABC(int year){
    bool check = true; 

    int* hash = new int[10];
    
    for(int i = 0; i < 10; i++)
        hash[i] = 0;
    
    while(year){
        int r = year % 10; 
        if(hash[r] != 0){
            check = false;
            break;
        } else hash[r]++; 
        
        year /= 10;
    }
    
    delete[]hash;
    
    return check;
}

int main(){
    
    // cout << "nhap nam: ";
    int year; cin >> year;
    
    year++;
    
    while(true){
        if(ABC(year)){
            cout << year;
            break;
        }
        year++; 
    } 
        
    return 0;
}