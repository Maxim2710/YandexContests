#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

// Ваш код будет вставлен сюда

using namespace std;

Student make_student(string str_inf) {
    int pos = str_inf.find(';');
    int fir_mind = pos;
    Student stud;
    stud.name = str_inf.substr(0, pos);
    pos = str_inf.find(';', fir_mind + 1);
    stud.group = str_inf.substr(fir_mind + 1, pos - fir_mind - 1);
    fir_mind = pos;
    pos = str_inf.find(';', fir_mind + 1);
    bool flag = true;
    while (flag = true) {
        Course cur_course;
        cur_course.name = str_inf.substr(fir_mind + 1, pos - fir_mind - 1);
        fir_mind = pos;
        pos = str_inf.find(';', fir_mind + 1);

        cur_course.semester = stoi(str_inf.substr(fir_mind + 1, pos - fir_mind - 1));
        fir_mind = pos;
        pos = str_inf.find(';', fir_mind + 1);

        cur_course.finished = stoi(str_inf.substr(fir_mind + 1, (pos == string::npos ? pos : (pos - fir_mind - 1))));
        if (pos == string::npos) {
            break;
        }
        fir_mind = pos;
        pos = str_inf.find(';', fir_mind + 1);
        stud.courses.push_back(cur_course);
    }
    return stud;
}

bool is_upper(Student a, Student b) {
    if (a.group != b.group) {
        vector<string> vect;
        vect.push_back(a.group);
        vect.push_back(b.group);
        sort(vect.begin(), vect.end());
        return a.group == vect[0];
    }
    else {
        vector<std::string> names;
        names.push_back(a.name);
        names.push_back(b.name);

        sort(names.begin(), names.end());

        return a.name == names[0];
    }
}

bool is_debtor(Student stud, int cur_semester, int max_debt) {
    int cnt = 0;
    for (auto course : stud.courses) {
        if (course.semester >= cur_semester) {
            continue;
        }
        if (course.finished == false) {
            cnt++;
        }
    }
    return cnt > max_debt;
}

void print(vector<Student> data) {
    if (data.size() == 0) {
        cout << "Empty list!" << "\n";
        return;
    }

    string data1 = "";
    for (auto point : data) {
        if (point.group != data1) {
            data1 = point.group;
            cout << point.group << "\n";
        }
        cout << "- " << point.name << "\n";
    }
}

int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
                 students.end(),
                 std::back_inserter(expulsion_candidates),
                 [cur_semester, max_debt](const Student& student){
                     return is_debtor(student, cur_semester, max_debt);
                 });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}
