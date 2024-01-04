#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    bool checked = true;
    vector <string> vect;
    while (checked) {
        string str_19;
        cin >> str_19;
        if (str_19 == "end")
            break;
        vect.push_back(str_19);
    }
    int f;
    set<string> symb;
    for (auto iter = vect.begin(); iter != vect.end(); ++iter) {
        f = count(vect.begin(), vect.end(), *iter);
        if (f > 1) {
            symb.insert(*iter);
        }
    }
    for (auto iter = symb.begin(); iter != symb.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}