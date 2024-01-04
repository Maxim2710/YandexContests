#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

// Ваш код будет вставлен сюда

using namespace std;

Student make_student(string stroka) {
    int point = stroka.find(';');
    Student stud;
    stud.name = stroka.substr(0, point);
    stud.group = stroka.substr(point + 1, string::npos);
    return stud;
}

bool is_upper(Student fir, Student sec) {
    if (fir.group != sec.group) {
        vector<string> gruppa;
        gruppa.push_back(fir.group);
        gruppa.push_back(sec.group);
        sort(gruppa.begin(), gruppa.end());
        return fir.group == gruppa[0];
    } else {
        vector <string> name_list;
        name_list.push_back(fir.name);
        name_list.push_back(sec.name);
        sort(name_list.begin(), name_list.end());
        return fir.name == name_list[0];
    }
}

void print(vector <Student> vect) {
    if (vect.size() == 0) {
        cout << "Empty list!" << "\n";
        return;
    }

    string const_group = "";
    for (auto data : vect) {
        if (data.group != const_group) {
            const_group = data.group;
            cout << data.group << "\n";
        }
        cout << "- " << data.name << "\n";
    }
}

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::sort(students.begin(), students.end(), is_upper);

    print(students);
}
