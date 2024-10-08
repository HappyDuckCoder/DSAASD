#include<iostream>

using namespace std;

#define MAX 100
bool inscreasing(int a, int b){ return a > b; }
bool descreasing(int a, int b){ return a < b; }

class Array{

private: 
    int arr[MAX];
    int size;

public:
    Array(){ }

    int getSize() { return size; }
    void setSize(int size) { this->size = size; }

    int getItem(int index) { return arr[index]; } 
    void setItem(int index, int item) { arr[index] = item; }

    int findItem(int item) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }

    void _sort(bool (*cmp)(int a, int b)) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (cmp(arr[i], arr[j])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

};

istream &operator>>(istream &is, Array &array){
    int x;
    is >> x; 
    while(x < 0) is >> x;
    array.setSize(x);

    if(x == 0) return is;

    for(int i = 0; i < array.getSize(); i++) { 
        int tmp; 
        is >> tmp;
        array.setItem(i, tmp);
    }

    return is;
}

ostream &operator<<(ostream &os, Array &array){

    if(array.getSize() == 0) {
        return os << "empty array";
    }

    for(int i = 0; i < array.getSize(); i++) {
        os << array.getItem(i) << " ";
    }
    os << endl;
    return os;
}

int main() {

    Array array;
    cin >> array;   
    array._sort(inscreasing);
    cout << array;

    return 0;
}