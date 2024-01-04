#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Ваш код будет вставлен сюда

using namespace std;

bool compare(string a,string b) {
    int cntA = 0;
    int cntB = 0;
    for (int i = 0;i < a.size();i++) {
        if (a[i] == '1') {
            cntA += 1;
        }
    }
    for (int j = 0;j < b.size();j++) {
        if (b[j] == '1') {
            cntB += 1;
        }
    }
    if (cntA != cntB) {
        return cntA > cntB;
    }
    else {
        return stoi(a) < stoi(b);
    }
}

int main(){
    int count;
    std::cin >> count;

    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;

    std::sort(nums.begin(), nums.end(), compare);

    for(auto& line : nums) std::cout << line << ' ';
}