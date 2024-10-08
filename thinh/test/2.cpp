// Bài tập 2: Viết chương trình C++ cài đặt đối tượng điểm trong không gian Oxy, trong đó một điểm
// được định nghĩa gồm có tọa độ x và tọa độ y đều là số thực. Sinh viên hãy cài đặt các thao tác trên
// đối tượng điểm này:
// • Nhập và xuất điểm ra màn hình console
// • Tính khoảng cách giữa 2 điểm trong không gian Oxy, xuất ra thông tin khoảng cách

#include <iostream>
#include <cmath>

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


// int main() {

//     cPoint a(0, 0), b(0, 0);
//     cout << "input first point: "; a.Input();
//     cout << "input second point: "; b.Input();
//     cout << "first point: "; a.Output();
//     cout << "second point: "; b.Output();
//     cout << "distance: " << a.distance(b) << endl;

//     return 0;
// }