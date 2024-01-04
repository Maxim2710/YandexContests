#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
    int inputPclass;
    int inputAge;
    cin >> inputPclass >> inputAge;
    vector <vector<string>> results;
    int iterator = 0;
    ifstream inputFile;
    inputFile.open("train.csv");
    string my_line = "";
    getline(inputFile,my_line, '\r');
    my_line = "";
    while (not inputFile.eof()) {
        getline(inputFile,my_line, '\r');
        int passengerId;
        int survived;
        int pclass;
        string name;
        string sex;
        int age;
        string sibSp;
        string parch;
        string ticket;
        string fare;
        string cabin;
        string embarked;

        string controlPassengerId;
        string controlSurvived;
        string controlPclass;
        string controlAge;

        string summatorName1;
        string summatorName2;
        string name_fake;

        stringstream inputString(my_line);

        getline(inputString,controlPassengerId,',');
        if (controlPassengerId == "") {
            passengerId = 0;
        }
        else {
            passengerId = stoi(controlPassengerId);
        }
        getline(inputString,controlSurvived, ',');
        if (controlSurvived == "") {
            survived = 0;
        }
        else {
            survived = stoi(controlSurvived);
        }
        getline(inputString,controlPclass,',');
        if (controlPclass == "") {
            pclass = 0;
        }
        else {
            pclass = stoi(controlPclass);
        }
        getline(inputString,summatorName1,',');
        getline(inputString,summatorName2,',');
        name_fake = summatorName1 + "," + summatorName2;
        string cur = "";
        for (int i = 1; i < name_fake.size() - 1;i++) {
            cur += name_fake[i];
        }
        name = cur;
        name = regex_replace(name,regex("\"\""),"\"");
        getline(inputString, sex, ',');
        getline(inputString,controlAge,',');
        if (controlAge == "") {
            age = 0;
        }
        else {
            age = stoi(controlAge);
        }
        getline(inputString, sibSp, ',');
        getline(inputString, parch, ',');
        getline(inputString, ticket, ',');
        getline(inputString, fare, ',');
        getline(inputString, cabin, ',');
        getline(inputString, embarked, '\r');
        if (sex == "female" && age > inputAge && inputPclass == pclass) {
            results.push_back(vector<string>{to_string(age), name} );
        }
        my_line = "";
    }
    sort(results.begin(), results.end(), [](vector<string> first_elem, vector<string> second_elem){
        if (first_elem[0] == second_elem[0]) {
            return first_elem[1] < second_elem[1];
        }
        int fir_an = first_elem[0] == "" ? 0 : stoi(first_elem[0]);
        int sec_an = second_elem[0] == "" ? 0 : stoi(second_elem[0]);
        return fir_an < sec_an;
    });
    for(int i = 0; i < results.size();i++) {
        cout << results[i][1] << "\n";
    }
    return 0;
}