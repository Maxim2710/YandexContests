#include <iostream>
#include <string>
#include <vector>

class Any{
    enum class Type{
        INT,
        DOUBLE,
        STRING,
        VECTOR_ANY_PTR
    };

    void* data;
    Type type;

public:
    Any(int* data);
    Any(double* data);
    Any(std::string* data);
    Any(std::vector<Any*>* data);
    ~Any();

    operator int();
    operator double();
    operator std::string();
    operator std::vector<Any*>*();

    friend std::ostream& operator<<(std::ostream& out, const Any& val);
};

std::ostream& operator<<(std::ostream& out, const Any& o);

int main(){
    Any data(new std::vector<Any*>());

    std::vector<Any*>* array = (std::vector<Any*>*)data;

    int ints_count;
    std::cin >> ints_count;
    for(int i=0; i<ints_count; i++){
        int value;
        std::cin >> value;
        Any* temp = new Any(new int(value));
        array->push_back(temp);
    }

    int doubles_count;
    std::cin >> doubles_count;
    for(int i=0; i<doubles_count; i++){
        double value;
        std::cin >> value;
        Any* temp = new Any(new double(value));
        array->push_back(temp);
    }

    int strings_count;
    std::cin >> strings_count;
    for(int i=0; i<strings_count; i++){
        std::string value;
        std::cin >> value;
        Any* temp = new Any(new std::string(value));
        array->push_back(temp);
    }

    int i = 0; double d = 0; std::string s = "";
    for(auto value: *array){
        try{ i += (int)(*value); }
        catch(...){ }

        try{ d += (double)(*value); }
        catch(...){ }

        try{ s += (std::string)(*value); }
        catch(...){ }
    }

    Any ai(new int(i));
    Any ad(new double(d));
    Any as(new std::string(s));

    std::cout << data << "\n" << ai << ' ' << ad <<  ' ' << as;
}

// Ваш код здесь

using namespace std;

Any::Any(int* data) {
    this->data = data;
    this->type = Type::INT;
}

Any::Any(double* data) {
    this->data = data;
    this->type = Type::DOUBLE;
}

Any::Any(string* data) {
    this->data = data;
    this->type = Type::STRING;
}

Any::Any(vector<Any*>* data) {
    this->data = data;
    this->type = Type::VECTOR_ANY_PTR;
}

Any::~Any() {
    if (type == Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<vector<Any*>*>(data);
        for (auto &it : *realPtr) {
            delete it;
        }
        delete realPtr;
    } else if (type == Type::INT) {
        int* realPtr = static_cast<int*>(data);
        delete realPtr;
    } else if (type == Type::DOUBLE) {
        double* realPtr = static_cast<double*>(data);
        delete realPtr;
    } else if (type == Type::STRING) {
        string* realPtr = static_cast<string*>(data);
        delete realPtr;
    }
}

Any::operator int() {
    if (type != Type::INT) {
        throw "";
    }
    return *static_cast<int*>(data);
}

Any::operator double() {
    if (type != Type::DOUBLE) {
        throw "";
    }
    return *static_cast<double*>(data);
}

Any::operator string() {
    if (type != Type::STRING) {
        throw "";
    }
    return *static_cast<string*>(data);
}

Any::operator vector<Any*>*() {
    if (type != Type::VECTOR_ANY_PTR) {
        throw "";
    }
    return static_cast<vector<Any*>*>(data);
}

ostream& operator<<(ostream& out, const Any& val) {
    if (val.type == Any::Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<vector<Any*>*>(val.data);
        for (auto &it : *realPtr) {
            out << *it << " ";
        }
    } else if (val.type == Any::Type::INT) {
        int* true_pointer = static_cast<int*>(val.data);
        out << *true_pointer;
    } else if (val.type == Any::Type::DOUBLE) {
        double* true_pointer = static_cast<double*>(val.data);
        out << *true_pointer;
    } else if (val.type == Any::Type::STRING) {
        string* true_pointer = static_cast<string*>(val.data);
        out << *true_pointer;
    }
    return out;
}