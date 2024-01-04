#include <iostream>
using namespace std;

int main() {
    int A;
    int B;
    int C;
    cin >> A >> B >> C;
    if (abs(A - B) > abs(A - C)) {
        cout << "C" << " " << abs(A - C) << endl;
    }
    else {
        cout << "B" << " " << abs(A - B) << endl;
    }
}