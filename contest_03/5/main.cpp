#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    string elem;
    map <string,int> my_bag;
    while (i < n) {
        cin >> elem;
        my_bag[elem] += 1;
        i++;
    }
    int max_el = 0;
    set <string> res;
    for (auto [word,cnt] : my_bag) {
        if (cnt > max_el) {
            max_el = cnt;
            res.clear();
        }
        if (cnt == max_el) {
            res.insert(word);
        }
    }
    for (auto w : res) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}