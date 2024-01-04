#include <iostream>

class Keeper{
    int trash;
    int secret;

public:
    Keeper(){
        std::cin >> secret;
    }
};

// Ваш код здесь

struct Hack {
    int trasher_bag;
    int secret;
};

int hack_it(Keeper kep) {
    Hack* hack = reinterpret_cast<Hack*>(&kep);
    return hack->secret;
}

int main(){
    Keeper keeper;
    int secret= hack_it(keeper);
    std::cout << secret;
}