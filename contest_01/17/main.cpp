#include <iostream>
using namespace std;
long location(int my_bag[], int i1, int i2){
    long h = -1,spec = 0,mad = 0,x;
    if (i1 < i2) {
        for (int i = i1; i <= i2; ++i){
            x = my_bag[i];
            if (x >= h) {
                h = x;
                mad = 0;
            } else {
                spec += (h - x);
                ++mad;
            }
        }
    } else {
        for (int i = i1; i >= i2; --i){
            x = my_bag[i];
            if (x >= h) {
                h = x;
                mad = 0;
            } else {
                spec += (h - x);
                ++mad;
            }
        }
    }
    if (x < h) {
        spec = spec - mad * (h - x);
    }
    return spec;
}

int main(){
    long cur, n, reg = -1, point=0;
    cin >> n;
    int *mas = new int[n];
    for (int i=0; i<n; ++i)
    {
        cin >> cur;
        mas[i] = cur;
        if (cur > reg) {
            reg = cur;
            point = i;
        }
    }
    cout << location(mas, 0, point) + location(mas, n-1, point) << endl;
    return 0;
}