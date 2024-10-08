#include <iostream>
#include <string> 

using namespace std;    
struct Pupil{
    string name;
    float math, literature;
};

void input(Pupil &p){
    getline(cin, p.name);
    cin >> p.math >> p.literature;
}