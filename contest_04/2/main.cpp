#include <iostream>
#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

using namespace std;

int main() {
    int init_user;
    cin >> init_user;

    ifstream file;
    file.open("data.json");
    json my_data = json::parse(file);

    int count = 0;
    for (auto &project_control : my_data) {
        for (auto &task_control : project_control["tasks"]) {
            if (task_control["user_id"] == init_user && task_control["completed"]) {
                count ++;
            }
        }
    }
    cout << count << endl;
    return 0;
}