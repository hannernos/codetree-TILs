#include <iostream>
#include <vector>
using namespace std;

//var
int N;
char map[21][21];
int st_dy, st_dx;
int des_dy, des_dx;
int des_list[10][2];
bool coin_exists[10] = {}; 

int coins[11] = {};
int coincount;

int tem_distance;
int min_distance = 1000000;
//func

int abs(int a) {
    return a < 0 ? -a : a;
}

int get_distance() {
    vector<pair<int, int>> uv;
    int total_distance_l = 0;

    uv.push_back({st_dy, st_dx});
    for (int i = 0; i < 3; i++) {
        uv.push_back({des_list[coins[i]][0], des_list[coins[i]][1]});
    }
    uv.push_back({des_dy, des_dx});

    for (int i = 0; i < 4; i++) {
        int tem_distance_l = abs(uv[i + 1].first - uv[i].first) + abs(uv[i + 1].second - uv[i].second);
        total_distance_l += tem_distance_l;
    }

    return total_distance_l;
}

void run(int depth, int last_coin) {
    if (depth == 3) {
        tem_distance = get_distance();
        if (tem_distance < min_distance) {
            min_distance = tem_distance;
        }
        return;
    }

    for (int i = last_coin + 1; i <= 9; i++) {
        if (!coin_exists[i]) continue; // 존재하는 동전만 고려
        if (depth > 0 && coins[depth - 1] >= i) continue; // 순차적 증가 확인
        coins[depth] = i;
        run(depth + 1, i);
    }
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                st_dy = i; st_dx = j;
            }
            if (map[i][j] == 'E') {
                des_dy = i; des_dx = j;
            }
            if (isdigit(map[i][j])) {
                int coinNum = map[i][j] - '0';
                des_list[coinNum][0] = i;
                des_list[coinNum][1] = j;
                coin_exists[coinNum] = true;
            }
        }
    }
}

int main() {
    init();
    run(0, 0);
    cout << (min_distance == 1000000 ? -1 : min_distance);
    return 0;
}