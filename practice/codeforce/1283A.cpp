#include<iostream>

using namespace std;

int main(){
    
    int time; cin >> time;
    while(time--){
        int hh, mm;
        cin >> hh >> mm; 
        
        int hourRemain = 24 - hh; 
        int minuteRemain = 60 - mm; 
        
        cout << minuteRemain + (hourRemain - 1) * 60 << endl; 
    }
    
    return 0;
}