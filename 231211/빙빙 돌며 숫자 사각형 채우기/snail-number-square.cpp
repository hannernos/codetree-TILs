#include <iostream>
using namespace std;

int n, m;
int arr[101][101];
int cnt;

int y, x;
int dir;
int dir_y[5] = {0, 0, 1, 0, -1};
int dir_x[5] = {0, 1, 0, -1, 0};

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << "\n";
    }
}

void conflict_check(int py, int px) {
    if (py < 1 || px < 1 || py > n || px > m || arr[py][px] != 0) {
        // 90도 회전
        dir = (dir % 4) + 1;
    } else {
        // 앞으로 진행
        y = py;
        x = px;
        arr[y][x] = ++cnt;
    }
}

void run() {
    int nm = n * m;
    while (cnt < nm) {
        conflict_check(y + dir_y[dir], x + dir_x[dir]);
    }
}

void init() {
    cin >> n >> m;    
    y = 1; x = 1;
    cnt = 1;
    dir = 1;
    arr[1][1] = 1;
}

int main() {
    init();
    run();
    print();
    return 0;
}