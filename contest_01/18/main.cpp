#include <iostream>

using namespace std;

void in_26_SS(int N) {
    int arr[1000000];
    int cnt = 0;
    while (N != 0) {
        arr[cnt] = N % 26;
        N = N / 26;
        cnt++;
    }
    for (int k = 0;k < cnt - 1;k++) {
        if (arr[k] <= 0) {
            arr[k] += 26;
            arr[k+1] -= 1;
        }
    }
    for (int x = cnt;x >= 0;x--) {
        if (arr[x] > 0) {
            cout << char('A' + arr[x] - 1);
        }
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    in_26_SS(num);
}