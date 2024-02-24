/*
*/
#include <iostream>

using namespace std;

void init();
void run();
void mv(char a);
bool cango(int ny, int nx);

void print();

int N, T;
char LRF[100001];
int arr[101][101];


int x, y;
int dir_x[4] = { 0, 1, 0, -1 };// N E S W
int dir_y[4] = { -1, 0, 1, 0 };
int dir;
long long cnt;

int main() {

    init();
    run();
    return 0;
}

void init() {
    cin >> N >> T >> LRF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    dir = 0;
    y = N / 2;
    x = y;
    cnt = arr[y][x];
}
void run() {
    for (int i = 0; i < T; i++) {
        mv(LRF[i]);
    }
    cout << cnt;

}
bool cango(int ny, int nx) {
    if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
        return false;
    }
    return true;
}
void mv(char a) {
    int nx, ny;
    switch (a) {
    case 'L':
        dir = dir - 1 + 4;
        break;
    case 'R':
        dir = dir + 1;
        break;
    case 'F':
        nx = x + dir_x[dir];
        ny = y + dir_y[dir];
        if (cango(ny, nx)) {
            x = nx;
            y = ny;
            cnt += arr[y][x];
            print();
        }

        return;
        break;
    default:
        break;
    }
    dir = dir % 4;
}

void print() {
    //cout << "cnt : "<<cnt << endl;
}