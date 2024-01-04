#include <iostream>

// Ваш код будет вставлен сюда
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2;i <= sqrt(n);i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
