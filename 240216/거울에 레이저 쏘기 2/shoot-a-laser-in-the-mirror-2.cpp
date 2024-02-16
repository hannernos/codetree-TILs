#include <iostream>
using namespace std;


void init();
void run();
void stpos();
void stpos_each(int a);


void print();
void print2();

//var
char arr[1002][1002];
int N;
char t;

int K;
int y, x;
int dir_x[4] = { 1,0,-1,0 }; // R D L U
int dir_y[4] = { 0,-1,0,1 };

int dir;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    stpos();

    run();
    return 0;
}


void init() {
    char buf[10001];
    cin >> N;
    for (int i = 0; i < N; i++) {
        //       for (int j = 1; j <= N; j++) {
        //           cin >> arr[i][j];
        //     }
        cin >> buf;
        for (int j = 0; j < N; j++) {
            arr[N-i][j + 1] = buf[j];
        }
    }
    cin >> K;
}
void stpos() {

    switch ((K - 1) / N) {
    case 0:
        dir = 1;
        y = N;
        stpos_each(0);
        break;

    case 1:
        dir = 2;
        x = N;
        stpos_each(1);
        break;

    case 2:
        dir = 3;
        y = 1;
        stpos_each(2);
        break;

    case 3:
        dir = 0;
        x = 1;
        stpos_each(3);
        break;
    default:
        break;
    }


}

void stpos_each(int a) {
    int tem;
    print2();
    if ((K % N) != 0) {
        tem = (K % N);
    }
    else {
        tem = N;
    }

    switch (a) {
    case 0:
        x = tem;
        break;

    case 1:
        y = N - (tem - 1);
        break;

    case 2:
        x = N - (tem - 1);
        break;

    case 3:
        y = tem;
        break;

    default:
        break;
    }
}

void run() {
    print();
    /*
    현재 레이저 위치가 밖으로 나갈때까지,
    시뮬레이션으로 계속 돌리기
    R D L U
    */
    int count = 0;
    int nxt_x, nxt_y;
    while (y > 0 && x > 0 && x <= N && y <= N) {
        //dir 반사 계산
        if (arr[y][x] == '/') {
            switch (dir) {
            case 0:
                dir = 3;
                break;
            case 1:
                dir = 2;
                break;
            case 2:
                dir = 1;
                break;
            case 3:
                dir = 0;
                break;
            default:
                break;
            }
        }
        else if (arr[y][x] == '\\') {
            switch (dir) {
            case 0:
                dir = 1;
                break;
            case 1:
                dir = 0;
                break;
            case 2:
                dir = 3;
                break;
            case 3:
                dir = 2;
                break;
            default:
                break;
            }
        }
        else {}

        //이후 진행된 위치 계산
        x = x + dir_x[dir];
        y = y + dir_y[dir];
        count++;
        print();

    }

    cout << count;
}





void print() {
    // cout << "x : " << x << ", y: " << y << ", dir: "<<dir<<endl;
}
void print2() {
    // for (int i = N; i > 0; i--) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << arr[i][j] << " ";
    //     }cout << endl;
    // }
}