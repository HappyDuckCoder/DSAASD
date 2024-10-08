#include<iostream>
#include<cmath>

using namespace std;


class cPoint {

private: 
    int x, y;

    void input() {
        cout << "nhap toa do va tung do: ";
        cin >> x >> y;
    }

    void output() { 
        cout << "( " << x << ", " << y << " )\n";
    }


public: 
    cPoint();
    cPoint(int x, int y){ this->x = x; this->y = y; }
    int getX() { return this->x; }
    int getY() { return this->y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    void Input() { input(); }
    void Output() { output(); }

    double distance(cPoint a) {
        return sqrt( pow(x - a.x, 2) + pow(y - a.y, 2) );
    }
};


