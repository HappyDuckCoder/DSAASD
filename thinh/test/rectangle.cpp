// Bài tập 3: Viết chương trình C++ cài đặt đối tượng hình chữ nhật trong không gian Oxy gồm có 4
// đỉnh (theo thứ tự kim đồng hồ, đỉnh đầu tiên ở góc trái trên), trong đo mỗi đỉnh của hình chữ nhật
// là 1 điểm (x, y) trong không gian Oxy. Sinh viên hãy cài đặt các thao tác trên đối tượng hình chữ
// nhật này:
// • Nhập và xuất thông tin hình chữ nhật ra màn hình console
// • Kiểm tra xem hình chữ nhật có hợp lệ hay không dựa trên thông tin các đỉnh, xuất ra màn
// hình kết quả kiểm tra hợp lệ hay không hợp lệ.
// • Tính chu vi và diện tích hình chữ nhật nếu hình chữ nhật hợp lệ.
// • Vẽ sơ đồ lớp UML cho bài tập này

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
    cPoint(){};
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

class cRectangle {

private: 
    cPoint p1, p2, p3, p4;

    void input() {
        cout << "nhap toa do tren ben trai: ";
        p1.Input(); 
        cout << "nhap toa do tren ben phai: ";
        p2.Input(); 
        cout << "nhap toa do duoi ben phai: ";
        p3.Input(); 
        cout << "nhap toa do duoi ben trai: ";
        p4.Input(); 
    }

    void output() { 
        cout << "4 dinh hinh chu nhat theo thu tu kim dong ho: \n";
        p1.Output();
        p2.Output();
        p3.Output();
        p4.Output();
    }


public: 
    cRectangle(){};
    cRectangle(cPoint p1, cPoint p2, cPoint p3, cPoint p4){ 
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
    }
    cPoint getP1() { return this->p1; }
    cPoint getP2() { return this->p2; }
    cPoint getP3() { return this->p3; }
    cPoint getP4() { return this->p4; }
    void setP1(cPoint x) { this->p1 = x; }
    void setP2(cPoint x) { this->p2 = x; }
    void setP3(cPoint x) { this->p3 = x; }
    void setP4(cPoint x) { this->p4 = x; }

    void Input() { input(); }
    void Output() { output(); }

    bool checkValidRectangle() {
        int x1 = p1.getX(), x2 = p2.getX(), x3 = p3.getX(), x4 = p4.getX();
        int y1 = p1.getY(), y2 = p2.getY(), y3 = p3.getY(), y4 = p4.getY();

        // A------B
        // |      |
        // |      |
        // |      |
        // D------C

        return (y1 == y2 && y3 == y4) && (x1 == x4 && x2 == x3);
    }

    double getPerimeter() {
        return p1.distance(p2) + p2.distance(p3) + p3.distance(p4) + p4.distance(p1);
    }

    double getArea(){
        return p1.distance(p2) * p2.distance(p3);
    }
};

int main() {

    cout << "nhap thong tin hinh chu nhat: \n";
    cRectangle r(cPoint(0, 0), cPoint(0, 0), cPoint(0, 0), cPoint(0, 0));
    r.Input();

    while(!r.checkValidRectangle()) {
        cout << "nhap lai thong tin hinh chu nhat: \n";
        r.Input();
    }

    double perimeter = r.getPerimeter();
    double area = r.getArea();
    cout << "chu vi hinh chu nhat: " << perimeter << "\n";
    cout << "dien tich hinh chu nhat: " << area << "\n";    

    r.Output();

    return 0;
}


