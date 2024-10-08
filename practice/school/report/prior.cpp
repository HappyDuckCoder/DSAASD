#include <iostream>
#include <vector>
#include <queue> 
#include <functional>
using namespace std;

vector<string> customers = {"A", "B", "C", "D", "E", "F", "G", "H", "K", "I"};
vector<string> VIP = {"Duck", "Thu", "Phu"};

struct CustomComparator {
    bool operator()(const string& name1, const string& name2) {
        bool isVIP1 = (find(VIP.begin(), VIP.end(), name1) != VIP.end());
        bool isVIP2 = (find(VIP.begin(), VIP.end(), name2) != VIP.end());
        
        if(isVIP1 == isVIP2){
            return name1 > name2;
        }

        return !isVIP1;
    }
};

int main() {
    priority_queue<string, vector<string>, CustomComparator> pq;
    
    pq.push(customers[1]);
    pq.push(customers[3]);
    pq.push(customers[5]);
    pq.push(VIP[1]);
    pq.push(customers[7]);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
