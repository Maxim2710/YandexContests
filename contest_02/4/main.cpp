#include <iostream>
#include <tuple>

// Ваш код будет вставлен сюда

#include <utility>
#include <numeric>

using namespace std;

pair <int,int> reduce(int i,int j) {
    int nod = gcd(i,j);
    return make_pair(i / nod, j / nod);
}

tuple <int,int,int> find_lcm(int t,int k) {
    int nok = lcm(t,k);
    return make_tuple(nok,nok / t,nok / k);
}

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}