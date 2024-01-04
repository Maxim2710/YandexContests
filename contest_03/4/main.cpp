#include <iostream>
#include <set>

using namespace std;

int main() {
    int n1;
    int n2;
    set <string> fir_vec;
    set <string> res;
    cin >> n1;
    int i = 0;
    int j = 0;
    string word;
    while (i < n1) {
        cin >> word;
        fir_vec.insert(word);
        i++;
    }
    cin >> n2;
    while (j < n2) {
        cin >> word;
        if (fir_vec.count(word) > 0) {
            res.insert(word);
        }
        j++;
    }
    if (res.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (auto& k : res) {
        cout << k << " ";
    }
    cout << endl;
}