#include <iostream>
#include <string>

using namespace std;

bool num_check(char el) {
    return 48 <= el && el <= 57;
}


void re_line(string& st, string& line) {
    while (st[0] != '(' && st.empty() == false) {
        line += " " + string(1, st[0]) ;
        st = st.substr(1);
    }
    st = st.substr(1);
}

int rasstanovka(char elem) {
    if (elem == '^') {
        return 3;
    }
    else if (elem == '/' || elem == '*' || elem =='%') {
        return 2;
    }
    else if (elem == '-' || elem == '+') {
        return 1;
    }
    else {
        return 0;
    }
}

bool oper_check(char el) {

    return el == '+' || el == '-' || el == '*' || el == '/' || el == '%' || el == '^';

}

int main() {
    string inp;
    cin >> inp;
    string res_str = "";
    string line = "";

    for (auto& el : inp) {
        string reg(1, el);
        if (reg == "(") {
            line = '(' + line;
        }
        else if (reg == ")") {
            re_line(line, res_str);
        }
        else if (oper_check(el)) {
            res_str += " ";

            while (line.empty() == false && rasstanovka(el) <= rasstanovka(line[0])) {
                if (el == line[0] && el == '^') {
                    break;
                }
                res_str += string(1, line[0]) + " ";

                line = line.substr(1);
            }
            line = reg + line;
        }
        if (num_check(el)) {
            res_str += string(1, el);
        }
    }
    cout << res_str << " ";

    for (auto& i: line){
        cout << i << " ";
    }

    return 0;
}