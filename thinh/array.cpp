#include<iostream>
using namespace std;

#define MAX 100

struct Array{
    int a[MAX];
    int size;
};

void input(Array &array){
    cin >> array.size;
    for(int i = 0; i < array.size; i++){
        cin >> array.a[i];
    }
}

void output(Array array){
    for(int i = 0; i < array.size; i++){
        cout << array.a[i] << " ";
    }
    cout << endl;
}

void _sort(Array &array, void (*sort)(Array &array)){   
    sort(array);
}

bool ins(int a, int b){ return a < b; } 
bool des(int a, int b){ return a > b; }
void sort_(Array &array, bool (*cmp)(int a, int b)){
    for(int i = 0; i < array.size - 1; i++){
        for(int j = i + 1; j < array.size; j++){
            if(cmp(array.a[i], array.a[j])){
                swap(array.a[i], array.a[j]);
            }
        }
    }
}

int main(){
    Array array;
    input(array);

    output(array);
    return 0;
}