#include <iostream>
using namespace std;

int main() {
    string a;
    cin >> a;
    string itog = "";
    for (int i = 0;i < a.size();i++) {
        int cnt = 1;
        if (a[i] == a[i+1]) {
            while (i < a.size()-1 && a[i] == a[i+1]) {
                cnt +=1;
                i++;
            }
            itog += a[i] + to_string(cnt);
        }
        else {
            itog += a[i];
        }
    }
    cout << itog << endl;
}