#include <iostream>
#include <vector>
#include <string>

// Ваш код будет вставлен сюда
using namespace std;
bool my_move(vector <string>* field, int stroka, int stolb) {
    if ((*field)[stolb][stroka] != '#' && (*field)[stolb][stroka] != '?') {
        if ((*field)[stolb][stroka] == 'E') {
            return true;
        }
        else {
            (*field)[stolb][stroka] = 'W';
        }
    }
    return false;
}
bool is_can_exit_from_maze(vector <string> vect, int rowS, int colS) {
    vect[rowS][colS] = 'W';
    bool flag = false;
    bool prov = true;
    while(prov == true) {
        bool check_this_F = false;
        for (int y = 1; y < vect.size() - 1; y++) {
            for (int x = 1; x < vect[0].size() - 1; x++) {
                if (vect[y][x] == 'W') {
                    check_this_F = true;
                    flag = my_move(&vect, x-1, y);
                    if (flag == true) {
                        break;
                    }
                    flag = my_move(&vect, x+1, y);
                    if (flag == true) {
                        break;
                    }
                    flag = my_move(&vect, x, y-1);
                    if (flag == true) {
                        break;
                    }
                    flag = my_move(&vect, x, y+1);
                    if (flag == true) {
                        break;
                    }
                    vect[y][x] = '?';
                }
            }
            if (flag == true) {
                break;
            }
        }
        if (check_this_F == false || flag == true) {
            break;
        }
    }
    return flag;
}

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода

    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);

    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}
