// point.h 

# ifdef POINT_H
# define POINT_H

#include <iostream>
#include <cmath>

using namespace std;

class cPoint {

private: 
    int x, y;

public: 
    cPoint();
    cPoint(int x, int y);

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    void input();
    void output();

    double distance(cPoint a);
};

# endif
