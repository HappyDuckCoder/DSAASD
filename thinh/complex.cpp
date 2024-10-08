#include <iostream>
#include <math.h>

using namespace std;

struct Complex{
    float real;
    float img;
};

void input(Complex &c){
    cin >> c.real >> c.img;
}

void output(Complex c){
    cout << c.real << " + " << c.img << "i";
    cout << endl;
}

float computeModule(Complex c){
    return sqrt(c.real * c.real + c.img * c.img);
}

Complex operator + (Complex c1, Complex c2){
    Complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    return c;
}

Complex operator - (Complex c1, Complex c2){
    Complex c;
    c.real = c1.real - c2.real;
    c.img = c1.img - c2.img;
    return c;
}

Complex operator * (Complex c1, Complex c2){
    Complex c;
    c.real = c1.real * c2.real - c1.img * c2.img;
    c.img = c1.real * c2.img + c1.img * c2.real;
    return c;
}

Complex operator / (Complex c1, Complex c2){
    Complex c; 
    float moduleC2 = computeModule(c2);

    c.real = (c1.real * c2.real + c1.img * c2.img) / moduleC2;
    c.img = (c1.img * c2.real - c1.real * c2.img) / moduleC2;

    return c;;
} 

int main(){

    Complex c1, c2;
    Complex res1, res2, res3, res4; 

    input(c1);
    input(c2);

    res1 = c1 + c2;
    res2 = c1 - c2;
    res3 = c1 * c2;
    res4 = c1 / c2;

    output(res1);
    output(res2);
    output(res3);
    output(res4);

    return 0;

}