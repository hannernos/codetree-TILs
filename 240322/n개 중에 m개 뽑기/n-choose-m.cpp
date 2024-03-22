#include <iostream>
#include<vector>

using namespace std;

void init();
void run(int lev, int used_num);
void print();
//var
int n, m;
vector<int> mv;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run(1,0);
    return 0;
}

void init() {
    cin >> n >> m; //1 이상 N 이하 숫자 중 M개 골라
}


void run(int lev, int used_num) {
    if (lev == n+1) {
        if (used_num == m) {
            print();
        }
        return;
    }

    mv.push_back(lev);
    run(lev + 1, used_num + 1);
    mv.pop_back();

    run(lev + 1, used_num);
}

void print() {
    for (int i = 0; i < m; i++) {
        cout << mv[i] << " ";
    }cout << endl;
}