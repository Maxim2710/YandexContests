#include <iostream>
#include <vector>

// Ваш код здесь

#include <cmath>

class Shape {
public:
    virtual double getPerimeter() const = 0;
};

class Rectangle: public Shape {
public:
    Rectangle(int a,int b) {
        this->a = a;
        this->b = b;
    }
    double getPerimeter() const {
        return (a + b) * 2;
    }
private:
    int a,b;
};

class Circle: public Shape {
public:
    Circle(int r) {
        this -> r = r;
    }
    double getPerimeter() const {
        return 2 * M_PI * r;
    }
private:
    int r;
};

class Triangle: public Shape {
public:
    Triangle(int a,int b,int c) {
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }
    double getPerimeter() const {
        if (a >= b + c || b >= a + c || c >= a + b) {
            return 0;
        }
        else {
            return a + b + c;
        }
    }
private:
    int a,b,c;
};

int main(){
    int momentum;
    std::cin >> momentum;
    srand(momentum);
    std::vector <Shape*> shapes(rand() % 100 + 1);
    for (int i=0; i < shapes.size(); i++){
        int a = rand()%10 + 1, b = rand()%10 + 1, c = rand()%10 + 1;
        if (rand() % 3 == 0) shapes[i] = new Rectangle(a, b);
        else if (rand() % 3 == 1) shapes[i] = new Circle(c);
        else shapes[i] = new Triangle(a, b, c);
    }

    double sum = 0;
    for (auto shape : shapes) { sum += shape->getPerimeter();}
    std::cout << (int)sum;
}