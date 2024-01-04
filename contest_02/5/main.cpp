#include <iostream>

struct Complex{
    double re;  // Действительная часть
    double im;  // Мнимая часть
};

// Ваш код будет вставлен сюда

#include <sstream>
#include <numeric>
#include <complex>

using namespace std;

Complex make_complex(std::string input) {
    stringstream ss(input);
    Complex res;
    ss >> res.re;

    string mnimay;
    ss >> mnimay;
    if (mnimay.size() == 1) {
        string point;
        ss >> point;
        mnimay += point;
    }

    res.im = stod(mnimay);

    if (res.re == -0) {
        res.re = 0;
    }
    if (res.im == -0) {
        res.im = 0;
    }
    return res;
}

void print(Complex num) {
    string dei = "";

    if (num.re == -0) {
        num.re = 0;
    }
    if (num.im == -0) {
        num.im = 0;
    }
    if (num.im >= 0) {
        dei += "+";
    }
    dei += to_string(num.im);

    dei.erase ( dei.find_last_not_of('0') + 1, string::npos );
    dei.erase ( dei.find_last_not_of('.') + 1, string::npos );

    cout << num.re << dei << "j\n";
}

Complex sum(Complex a, Complex b) {
    complex<double> c1 = complex<double>(a.re, a.im);
    complex<double> c2 = complex<double>(b.re, b.im);
    complex<double> c_res = c1 + c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

Complex sub(Complex a, Complex b) {
    complex<double> c1 = complex<double>(a.re, a.im);
    complex<double> c2 = complex<double>(b.re, b.im);
    complex<double> c_res = c1 - c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

Complex mul(Complex a, Complex b) {
    complex<double> c1 = complex<double>(a.re, a.im);
    complex<double> c2 = complex<double>(b.re, b.im);
    complex<double> c_res = c1 * c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

Complex div(Complex a, Complex b) {
    complex<double> c1 = complex<double>(a.re, a.im);
    complex<double> c2 = complex<double>(b.re, b.im);
    complex<double> c_res = c1 / c2;
    Complex res;
    res.re = c_res.real();
    res.im = c_res.imag();
    return res;
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);

    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);

    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
