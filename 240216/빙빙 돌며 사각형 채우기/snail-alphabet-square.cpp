#include <iostream>
#define alp_num 26

using namespace std;


void init();
void run();
void print();
bool check(int py, int px);
//var
int n, m;
int arr[102][102];
int y, x;
//R D L U 아래가 위
int dir_x[4] = { 1, 0,-1, 0 };
int dir_y[4] = { 0, 1, 0,-1 };
int dir;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    print();
    return 0;
}

void init() {
    x = 1;
    y = 1;
    cin >> n >> m;
}

void run() {
    int cnt = 0;//+ 65 + 26
    dir = 0;
    char tem;
    while (cnt < n * m) {

        //이동 후 현재 위치 arr에 char갱신
        tem = ((cnt % alp_num) + 65);
        arr[y][x] = tem;

        //다음 목적지 판별 후 이동
        if (!check(y + dir_y[dir], x + dir_x[dir])) {
            dir = (dir + 1) % 4;
            //print();
        }else {}
        y = y + dir_y[dir];
        x = x + dir_x[dir];

        cnt++;
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << char(arr[i][j]) << " ";
        }cout << "\n";
    }cout << "\n";

}

bool check(int py, int px) {
    if (py<1 || py>n || px<1 || px>m || arr[py][px] > 0) {
        return false;
    }
    return true;
}