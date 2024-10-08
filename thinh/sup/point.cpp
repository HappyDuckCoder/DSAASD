#include "point.h"

// cPoint::cPoint() {}
// cPoint::cPoint(int x, int y) { this->x = x; this->y = y; }

int cPoint::getX() { return this->x; }
int cPoint::getY() { return this->y; }
void cPoint::setX(int x) { this->x = x; }
void cPoint::setY(int y) { this->y = y; }

void cPoint::input() {
    cout << "nhap toa do va tung do: ";
    cin >> x >> y;
}
void cPoint::output() { 
    cout << "( " << x << ", " << y << " )\n";
}

double cPoint::distance(cPoint a) {
    return sqrt( pow(x - a.x, 2) + pow(y - a.y, 2) );
}

int main() {
    cPoint p1, p2;
    p1.input();
    p2.input();
    cout << p1.distance(p2) << endl;
}

