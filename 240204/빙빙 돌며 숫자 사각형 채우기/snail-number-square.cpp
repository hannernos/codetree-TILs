#include <iostream>

using namespace std;

// var 
int n;
int m;

int dir_y[4] = { 0, 1, 0, -1 };
int dir_x[4] = { 1, 0, -1, 0 };
bool arr[101][101]; // 초기값 false, 이동한 후라면 true
int table[101][101];

int cell_cnt;
int tem_cnt;
// func 
void print() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}

bool cango(int y, int x) {
    if (y<1 || y>n || x<1 || x>m) {
        return false;
    }

    if (arr[y][x]) {
        return false;
    }
    return true;
}

void run() {
    int tem_y = 1;
    int tem_x = 1;
    int tem_dir = 0;

    tem_cnt = 1;
    for (int i = 0; i < cell_cnt; i++) {

        //마킹
        arr[tem_y][tem_x] = true;
        table[tem_y][tem_x] = tem_cnt;

        //print();

        //검증
        if (cango(tem_y + dir_y[tem_dir], tem_x + dir_x[tem_dir])) {

        }
        else {
            tem_dir = (tem_dir + 1) % 4;
        }
        //go
        tem_cnt++;

        tem_x = tem_x + dir_x[tem_dir];
        tem_y = tem_y + dir_y[tem_dir];


    }

    return;
}




void init() {
    cin >> n;
    cin >> m;
    cell_cnt = n * m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            arr[i][j] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    print();
    return 0;
}