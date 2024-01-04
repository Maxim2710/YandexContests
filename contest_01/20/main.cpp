#include <iostream>

#include <map>

using namespace std;

int main() {
    bool flag = true;
    string a, b;
    cin >> a;
    cin >> b;
    map<char, int> cntA, cntB;
    for (int j = 0; j < a.size(); j++) {
        cntA[a[j]]++;
    }
    for (int k = 0; k < b.size(); k++) {
        cntB[b[k]]++;
    }
    for (auto it = cntA.begin(); it != cntA.end(); ++it) {
        if (cntB[it->first] < it->second) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}