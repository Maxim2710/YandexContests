#include <iostream>
#include <string>

// Ваш код будет вставлен сюда

using namespace std;
#include <complex.h>

class Complex {
public:
    Complex(string input_value) {
        double re, im;
        stringstream inp(input_value);
        inp >> re;
        string im_str;
        inp >> im_str;
        if (im_str.length() == 1) {
            string add_piece;
            inp >> add_piece;
            im_str += add_piece;
        }
        im = stod(im_str);
        if (re == -0) {
            re = 0;
        }
        if (im == -0) {
            im = 0;
        }
        value = complex<double>(re, im);
    }
    Complex(complex<double> result_value) {
        value = result_value;
    }
    double re() const {
        return value.real();
    }
    double im() const {
        return value.imag();
    }
    Complex operator+(Complex &meaning) {
        return Complex(value + meaning.value);
    }
    Complex operator-(Complex &meaning) {
        return Complex(value - meaning.value);
    }
    Complex operator*(Complex &meaning) {
        return Complex(value * meaning.value);
    }
    Complex operator/(Complex &meaning) {
        return Complex(value / meaning.value);
    }

    friend std::ostream& operator<<(ostream& out, const Complex& num){
        double re = num.re();
        double im = num.im();
        out << (re == 0.0 ? 0.0 : re)
            << (im < 0 ? "":"+")
            << (im == 0.0 ? 0.0 : im) << 'j';
        return out;
    }
private:
    complex<double> value;
};

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);

    std::getline(std::cin, num, 'j');
    Complex c2(num);

    std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}