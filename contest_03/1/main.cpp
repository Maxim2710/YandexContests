#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n1;
    int n2;
    int num;
    vector <int> first_vec;
    vector <int> second_vec;
    cin >> n1;
    int i = 0;
    int q = 0;
    while (i < n1) {
        cin >> num;
        first_vec.push_back(num);
        i++;
    }
    cin >> n2;
    while (q < n2) {
        cin >> num;
        second_vec.push_back(num);
        q++;
    }
    vector <int> result_vec;
    for (auto& j: first_vec) {
        result_vec.push_back(j);
    }
    for (auto& k: second_vec) {
        result_vec.push_back(k);
    }
    sort(result_vec.begin(),result_vec.end());
    for (auto& k: result_vec) {
        cout << k << " ";
    }
}

