#include <iostream>
#include <map>

using namespace std;

int main() {
    int cnt;
    int reg;
    cin >> cnt;
    cin.ignore(1);
    map <string,int> my_bag;
    for (int i;i < cnt;i++) {
        string log;
        getline(cin,log,';');

        int mon;
        cin >> mon;
        cin.ignore(1);
        my_bag[log] = mon;
    }
    cin >> reg;
    for (int j = 0; j < reg;j++) {
        string log;
        cin >> log;
        cout << my_bag[log] << " ";
    }
    cout << endl;
    return 0;
}