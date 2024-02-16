#include <iostream>

using namespace std;

void init();
void run();
void print();
//var

int N;
int M;
int arr[102][102];


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    print();
    return 0;
}

void init() {

    cin >> N >> M;

}
void run() {
    int y = 1;
    int x = 1;
    int nxt_x, nxt_y;
    int dir = 0;
    int cnt = 1;

    //U R L D (아래가 위)
    int dir_x[4] = { 0,1,0,-1 };
    int dir_y[4] = { 1,0,-1,0 };

    while (cnt <= N * M) {
        //print();
        arr[y][x] = cnt;

        nxt_y = y + dir_y[dir];
        nxt_x = x + dir_x[dir];

        if (nxt_y<1 || nxt_y>N || nxt_x<1 || nxt_x>M || arr[nxt_y][nxt_x] > 0) {
            dir = (dir + 1) % 4;
            nxt_y = y + dir_y[dir];
            nxt_x = x + dir_x[dir];
        }
        y = nxt_y;
        x = nxt_x;

        cnt++;
    }

}

void print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << " ";
        }cout << "\n";
    }
}