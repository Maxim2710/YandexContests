#include <iostream>
using namespace std;

int main(){
    int num = 1;
    int N;
    int on_r = 3;
    int cnt_str = 1;
    int regulator = 1;
    cin >> N;
    while(num <= N){
        for (int k = 0; k < cnt_str && num <= N; k++)
            cout << num++ << ' ';
        cout << endl;
        cnt_str += regulator;
        if (cnt_str < 1){
            regulator = 1;
            cnt_str = 2;
            on_r+=1;
        } else if (cnt_str >= on_r){
            regulator = -1;
            cnt_str -= 2;
        }
    } return 0;
}