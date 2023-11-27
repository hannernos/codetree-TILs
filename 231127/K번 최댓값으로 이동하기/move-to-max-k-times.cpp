/*
문제 해결 전략


문제 풀면서 한 생각
 BFS 카테고리에 없었다면 DFS를 떠올리고 풀었을 것 같다
 전형적인 floodfill이 아니라 4방향 중 우선순위(큰 숫자, 적은 행,열)가 존재하고
 특정 route로 지렁이처럼 진행하기 때문에 dfs가 생각났었다

 문제 풀이 방향을 정하면서 헷갈리지 않도록 주의, 많이 풀어봐야 할 것 같다.

 문제를 처음에 제대로 이해하지 못함, 목적지가 여러개임
 첫번째 목적지에 도착하면 다시 새로운 목적지가 생김.

 단계별로 생각
 주어진 조건대로 이동 ->ok

 한 싸이클 이동을 마친 후에 visited를 초기화 해야 함
 어떤 기준으로 visited를 초기화 할 것인지 >?
 일단 flood fill로 다 퍼트리고 여기서 갈 수 있는 부분까지 다 진행한 이후에
 그 중에서 제일 높은 우선순위로 다시 run을 진행
    일단 다 퍼트리면서 high_num < 갱신시킴 나온 숫자 중에
    제일 높은 숫자로 갱신하고
    우선순위 이길때만 갱신

 이동 자체가 k번 반복임
 새로 이동할 위치가 없어도 바로 종료하고 출력

*/

#include <iostream>
#include <queue>
using namespace std;

//var
int n;
int k;

int r, c;

// 위 행, 좌 열 우선 적용
int dir_y[5] = { 0,-1,0,0,1 };
int dir_x[5] = { 0,0,-1,1,0 };

int arr[101][101] = { 0 };

//제일 높은 숫자
int h_num;
int h_r;
int h_c;

//func


void cmp_h(int h, int r, int c) {
    if (h > h_num) {
        h_num = h;
        h_r = r;
        h_c = c;
    }
    else if (h == h_num) {
        if (h_r > r) {
            h_r = r;
            h_c = c;
        }
        else if (h_r == r) {
            if (h_c > c) {
                h_c = c;
            }
        }
    }
}

bool cango(int y, int x) {
    if (y<1 || x<1 || y>n || x>n)return false;
    return true;
}

void run(int r0, int c0) {

    //var
    queue<pair<int, int>> mq;
    bool visited[101][101] = { false };
    int high_num;
    int x, y, dx, dy;

    int tem_path_num;
    int pre_path_num;
    //logic
    h_num = arr[r0][c0];
    h_r = r0;
    h_c = c0;

    mq.push({ r0,c0 });
    while (!mq.empty()) {
        y = mq.front().first;
        x = mq.front().second;
        pre_path_num = arr[y][x];
        mq.pop();

        //4방향 다 보는 것은 좋지만 우선순위중 최우선으로만 진행
        // 이후 해당 루트에서 막히면 바로 종료하고 해당 r c 리턴
        //행 열 조건은 방향으로 적용되고 높은 숫자는 추가구현 필요
        for (int i = 1; i <= 4; i++) {
            dx = x + dir_x[i];
            dy = y + dir_y[i];
            tem_path_num = arr[dy][dx];

            if (!cango(dy, dx))continue;
            if (visited[dy][dx])continue;
            if (tem_path_num > pre_path_num)continue;

            cmp_h(dy, dx, tem_path_num);

            visited[dy][dx] = true;
            mq.push({ dy,dx });

        }
    }
}
void run0() {
    //k번 다 돌면 true, 중간에 끊기면 false
    //근데 이렇게 일단 돌려도 중간에 갈 데 없으면 알아서 empty되서 나올 것같은데
    int r0, c0;
    r0 = r;
    c0 = c;
    for (int i = 1; i <= k; i++) {
        run(r0, c0);
        r0 = h_r;
        c0 = h_c;
    }
}

void init() {
    int tem;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tem;
            arr[i][j] = tem;
        }
    }
    cin >> r >> c;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run0();
    cout << h_r << " " << h_c;

    return 0;
}