#include<iostream>

using namespace std;    

class Mono{

private: 
    int co;
    int ex;

public:
    Mono(){};
    
    int getCo() { return co; }
    int getEx() { return ex; }
    void setCo(int co) { this->co = co; }
    void setEx(int ex) { this->ex = ex; }

    Mono operator+(Mono a) {
        Mono res;
        res.co = co + a.co;
        res.ex = ex;
        return res;
    }

    Mono operator-(Mono a) {
        Mono res;
        res.co = co - a.co;
        res.ex = ex;
        return res;
    }

    Mono operator*(Mono a) {
        Mono res;
        res.co = co * a.co;
        res.ex = ex + a.ex;
        return res;
    }

    Mono operator/(Mono a) { 
        Mono res;

        // if(a.co == 0) {
        //     cout << "Can't divide by 0";
        //     return {0, 0};
        // }

        res.co = co / a.co;
        res.ex = ex - a.ex;
        return res;
    }

};

istream &operator>>(istream &is, Mono &a) {
    int x, y;
    is >> x >> y;
    while(!y) cin >> y;
    a.setCo(x);
    a.setEx(y);
    return is;
}

ostream &operator<<(ostream &os, Mono &a) {
    os << a.getCo() << "x^" << a.getEx() << endl;
    return os;
}


int main(){

    Mono a, b;
    cin >> a >> b;
    Mono c = a + b;
    cout << c;

    return 0;
}