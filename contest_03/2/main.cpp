#include <iostream>
#include <vector>

using namespace std;

int main() {
    char inp;
    vector <char> st;
    do {
        cin >> inp;
        if (inp == '(' || inp == '[' || inp == '{') {
            st.push_back(inp);
        }
        if (inp == ')' || inp == ']' || inp == '}') {
            if (st.empty() || (!(inp == ')' && st[st.size()-1] == '(') && !(inp == '}' && st[st.size()-1] == '{') && !(inp == ']' && st[st.size()-1] == '['))) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                st.pop_back();
            }
        }
    } while(inp != '!');
    cout << (st.empty() ? "YES" : "NO") << endl;
    return 0;
}