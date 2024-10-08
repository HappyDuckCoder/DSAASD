// Bài tập 1: Viết chương trình C++ cài đặt đối tượng phân số, trong đó phân số được định nghĩa
// gồm có tử số và mẫu số với kiểu dữ liệu là số nguyên. 
// Sinh viên hãy cài đặt các thao tác trên đối tượng phân số này:
// • Nhập phân số từ console
// • Cộng, trừ, nhân, chia 2 phân số
// • Xuất phân số ra console theo 2 dạng:
//      o Xuất theo định dạng tử số / mẫu số
//      o Xuất theo định dạng kết quả phép chia của tử số và mẫu số (số thập phân)

#include <iostream>
#include <fstream>

using namespace std;

int findGCD(int a, int b){
    if(b == 0) return a;
    return findGCD(b, a % b);
}

class Fraction{

private: 
    int numerator;
    int denominator;

    void input(){
        cout << "Enter numerator and denominator: ";
        cin >> numerator >> denominator;
        while(!denominator){
            cout << "denominator can not equal zero, try input denominator again: ";
            cin >> denominator;
        }
    }

    void output(){
        cout << "format numerator / denominator: " << numerator << " / " << denominator << "\n";
        cout << "result: " << (numerator * 1.0) / (denominator * 1.0) << "\n"; 
    }

public: 
    Fraction(){}
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator(){ return numerator; }
    int getDenominator(){ return denominator; }
    void setNumerator(int numerator){ this->numerator = numerator; }
    void setDenominator(int denominator){ this->denominator = denominator; }

    void Input() { input(); }
    void Output() { output(); }

    Fraction inversion() {
        Fraction result;
        result.numerator = denominator;
        result.denominator = numerator;
        return result;
    }

    Fraction simplify() {
        Fraction result;

        if (numerator == 0) {
            result.numerator = 0;
            result.denominator = 1;
            return result;
        }

        int gcd = findGCD(numerator, denominator);
        result.numerator = numerator / gcd;
        result.denominator = denominator / gcd;
        return result;
    }

    Fraction operator + (Fraction a) {
        Fraction result(0, 0);
        result.numerator = numerator * a.denominator + denominator * a.numerator;
        result.denominator = denominator * a.denominator;
        return result.simplify();
    }

    Fraction operator - (Fraction a) {
        Fraction result;
        result.numerator = numerator * a.denominator - denominator * a.numerator;
        result.denominator = denominator * a.denominator;
        return result.simplify();
    }

    Fraction operator * (Fraction a) {
        Fraction result;
        result.numerator = numerator * a.numerator;
        result.denominator = denominator * a.denominator;
        return result.simplify();
    }

    Fraction operator / (Fraction a) {
        Fraction result;

        if (a.numerator == 0) {
            cout << "Can not divide by zero" << endl;
            return {0, 0};
        }

        result.numerator = numerator * a.denominator;
        result.denominator = denominator * a.numerator;
        return result.simplify();
    }
};

istream& operator>>(istream &is, Fraction &a) {
    int x, y;
    is >> x >> y;
    while(!y) cin >> y;
    a.setNumerator(x);
    a.setDenominator(y);
    return is;
}

ostream& operator<<(ostream &os, Fraction &a) {
    os << a.getNumerator() << " / " << a.getDenominator() << endl;
    return os;
}

int main(){

    Fraction a;
    Fraction b;

    // cout << "input first fraction: "; a.Input();
    // cout << "input first fraction: "; b.Input();

    cin >> a >> b;

    // cout << "DIVIDE FRACTION: \n";
    // Fraction f = a / b;
    // cout << f;


    cout << "ADD FRACTION: \n";
    Fraction c = a + b; 
    // cout << a + sb;
    cout << "SUB FRACTION: \n";
    Fraction d = a - b; 
    cout << d;
    cout << "MULTIPLE FRACTION: \n";
    Fraction e = a * b; 
    cout << e;
    

    return 0;
}

