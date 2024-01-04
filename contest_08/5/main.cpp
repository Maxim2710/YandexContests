#include <iostream>

// Ваш код здесь

class IntSharedPointer {
private:
    int* ref;
    int* point;
    void decreaseRefs() {
        (*ref)--;
        if (*ref == 0) {
            delete point;
            delete ref;
        }
    }
    void copyRefs(const IntSharedPointer& val) {
        point = val.point;
        ref = val.ref;
        (*ref)++;
    }

public:
    IntSharedPointer(int* pointer) {
        ref = new int{1};
        point = pointer;
    }
    IntSharedPointer(IntSharedPointer& val) {
        copyRefs(val);
    }
    ~IntSharedPointer() {
        decreaseRefs();
    }
    int& operator*() {
        return *point;
    }
    IntSharedPointer& operator=(const IntSharedPointer& val) {
        if (this == &val) {
            return *this;
        }
        decreaseRefs();
        copyRefs(val);
        return *this;
    }
};

void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);

    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);

    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}