/*
‘.’ (빈 공간), ‘S’ (시작점), ‘E' (도착점) 그리고 ‘1'이상 '9’이하의 숫자

*/
#include <iostream>
#include<vector>
using namespace std;

//var
int N;
char map[21][21];
int st_dy, st_dx;
int des_dy, des_dx;
int des_list[10][2];

//vector<int> coins;
int coins[11] = {};
int coincount;

int tem_distance;
int min_distance;
//func

int abs(int a) {
    if (a < 0) {
        a = -a;
    }return a;
}

int get_distance() {
    int a = coins[0];
    int b = coins[1];
    int c = coins[2];
    //cout << "a : " << a;
    //cout << "b : " << b;
    //cout << "c : " << c;
    //var
    vector<pair<int, int>> uv;;
    int tem_distance_l=0;
    int total_distance_l=0;

    int st_y_l;
    int st_x_l;
    int des_y_l;
    int des_x_l;

    //logic
    uv.push_back({ st_dy, st_dx });
    uv.push_back({ des_list[a][0], des_list[a][1] });
    uv.push_back({ des_list[b][0], des_list[b][1] });
    uv.push_back({ des_list[c][0], des_list[c][1] });
    uv.push_back({ des_dy, des_dx });

    for (int i = 0; i < 4;i++) {
        st_y_l = uv[i].first;
        st_x_l = uv[i].second;

        des_y_l = uv[i+1].first;
        des_x_l = uv[i+1].second;
        tem_distance_l = abs(des_y_l-st_y_l)+abs(des_x_l-st_x_l);
        total_distance_l += tem_distance_l;
        //cout << "total_element" << total_distance_l << endl;
    }
    
    //cout << "total" << total_distance_l << endl;
    return total_distance_l;
}
void print() {

    for (int i = 0; i < 3; i++) {
        cout << "0 : " << coins[0] << endl;
        cout << "1 : " << coins[1] << endl;
        cout << "2 : " << coins[2] << endl;
    }
}

void run(int depth,int tem_coin) {
    //시작점에서 출발하여 동전의 숫자가 증가하는 순서대로 
    // 최소 3개의 동전을 수집해 도착지에 도달하기 위해 
    // 필요한 최소 이동 횟수를 출력합니다. 
    // 불가능하면 -1 출력
    //* 꼭 번호가 증가하는 순서대로 수집해야 합니다 *//

    //숫자 위치는 다 아니까
    //이건 9개중에 숫자 3개 뽑는 문제
    //그 3개 경로를 계속 비교

    if (depth == 3) {
        //print();
        // 3개 뽑은 상태 -> 비교 ㄱㄱ
        tem_distance = get_distance();
        if (tem_distance < min_distance) {
            min_distance = tem_distance;
        }
        return;
    }

    for (int i = tem_coin+1; i < 9; i++) {
        coins[depth]=i;
        run(depth+1,i);
    }
    
}

void init() {
    min_distance = 1000000;
    coincount = 0;
    char tem;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tem;
            if (tem == 'S') {
                st_dy = i; st_dx = j;
            }
            if (tem == 'E') {
                des_dy = i; des_dx = j;
            }

            if (((tem - '0') > 0) && ((tem - '0') < 10)) {
                des_list[tem - '0'][0] = i;
                des_list[tem - '0'][1] = j;
                coincount++;
            }
            map[i][j] = tem;
        }
    }
    //cout << coincount;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    if (coincount < 3) {
        cout << "-1";
        return 0;
    }
    run(0,0);
    cout << min_distance;
    return 0;
}