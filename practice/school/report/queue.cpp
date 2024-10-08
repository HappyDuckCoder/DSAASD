#include <iostream>  
#include <queue>  
using namespace std;  

// create the function recognize the VIP 
struct compare{  
    bool operator()(const int& l, const int& r){  
        return l > r;  
    }  
};  

int main(){  
    //initiate a priority queue
    priority_queue<int,vector<int>, compare> pq;  

    pq.push(3);  
    pq.push(5);  
    pq.push(1);  
    pq.push(8);  

    while(!pq.empty()){  
        cout << pq.top() << endl;  
        pq.pop();  
    }  
    
    return 0;
}