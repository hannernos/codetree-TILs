/*
문제 해결 전략
가장 많이 초토화시킬 수 있는 영역의 수를 구하시오
1의 갯수가 k개라고 할 때

k개의 공간에 3가지중 하나씩을 넣고 이때의 파랑색 영역의 최댓값

우선 3^k 경우의 수
k는 최대 10

*/
#include <iostream>
#include <vector>

using namespace std;

//func
void init();
void run(int lev);
void get_explosion();
void set_map(int y, int x, int dir);

void print();

//var
int n;
int k;
int arr[101][101];
int max_bomb;
int tem_bomb;
vector<int> mv;
vector<pair<int, int>> kv;


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run(0);
    cout << max_bomb;
    return 0;
}


void init() {
    int tem;
    k = 0;
    max_bomb = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tem;
            //arr[i][j] = tem;
            if (tem == 1) {
                k++;
                kv.push_back({ i,j });
            }

        }
    }

}

void run(int lev) {
    if (lev == k) {
        //get tem bom
        get_explosion();

        return;
    }
    for (int i = 1; i <= 3; i++) {
        mv.push_back(i);
        run(lev + 1);
        mv.pop_back();
    }

}

void get_explosion() {
    // mv의 순서대로 맵에 표시하고 카운터 > 해봤자 최대 400
    int x, y;
    int dir;
    int dx, dy;

    tem_bomb = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        y = kv[i].first;
        x = kv[i].second;
        dir = mv[i];
        set_map(y, x, dir);
    }

    //compare with max
    if (max_bomb < tem_bomb) {
        max_bomb = tem_bomb;
    }

}

void set_map(int y, int x, int dir) {
    //상 하 좌 우
//    int dir_x[4] = { 0,0,-1,1 };
//    int dir_y[4] = { -1,1,0,0 };
    int dy, dx;
    pair<int, int> dirs[4][5] = {
        {},
        {{0,0}, {-2,0},{-1,0},{1,0},{2,0}},
        {{0,0},{-1,0},{1,0},{0,1},{0,-1}},
        {{0,0},{-1,-1},{1,1},{1,-1},{-1,1}}
    };

    for (int i = 0; i < 5; i++) {
        dy = y + dirs[dir][i].first;
        dx = x + dirs[dir][i].second;

        if (dy < 0 || dx < 0 || dy >= n || dx >= n) {
            continue;
        }
        if (arr[dy][dx] != 1) {
            arr[dy][dx] = 1;
            tem_bomb++;
        }
    }

    //print();
}

void print() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << "tem : " << tem_bomb << endl;
}