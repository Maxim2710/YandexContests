#include <iostream>

#include <fstream>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream file("data.txt");
    string target;
    cin >> target;

    map<string, int> res;
    string line;
    file >> line;

    while (line != "stopword") {
        if (line == target) {
            file >> line;
            if (line == "stopword") {
                break;
            }

            res[line]++;

        }

        file >> line;

    }

    if (res.empty()) {
        cout << "-" << endl;
        return 0;
    }

    map<int, set <string> > itog_bag;
    for (auto& [w, cnt] : res) {
        itog_bag[cnt].insert(w);
    }

    int cur_cnt = 0;
    for (auto i = itog_bag.rbegin(); i != itog_bag.rend(); ++i) {
        for (auto w : i->second) {
            cout << w << " ";
            if (++cur_cnt >= 3) {
                break;
            }
        }
        if (cur_cnt >= 3) {
            break;
        }
    }

    cout << endl;
    return 0;
}