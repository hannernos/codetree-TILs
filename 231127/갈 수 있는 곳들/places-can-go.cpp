#include<iostream>
#include<queue>
#include<set>

using namespace std;

int dir_y[5] = { 0,-1,0,1,0 };
int dir_x[5] = { 0,0,1,0,1 };
int k;
int n;
int arr[101][101]; // 0 can 1 X
bool visited_global[101][101] = { false };
queue<pair<int, int>> start_queue;
//set<int> ms;

//도착점 중복제거용(des도 정해져있는 줄 알았지만 아님)
// 그냥 int count 하면 되어 보임(도착점 리스트가 있는 줄 알았음)
//근데 생각해보니까 그것도 set 안쓰고 visited로 해결 가능, 잘못 생각함
//void count_answer(int y,int x) {
//    ms.insert(y * n + x);
//}
int count_answer() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited_global[i][j]) { 
                cnt++;
            }
        }
    }
    return cnt;
}


//인자로 넣고 여기서 visited 하거나 밖으로 빼거나
bool cango(int y,int x) {
    if (arr[y][x] == 1) {
        return false;
    }
    if (y<1 || x<1 || x>n || y>n)return false;
    return true;
}
void run(int py,int px) {
    visited_global[py][px] = true;
    int dx, dy;
    int x, y;
    queue<pair<int, int>>mq;
    bool visited[101][101] = { false };
    mq.push({ py,px });

    while (!mq.empty()) {

        y = mq.front().first;
        x = mq.front().second;
        mq.pop();

        for (int i = 1; i < 5; i++) {
            dy = y + dir_y[i];
            dx = x + dir_x[i];

            if (!cango(dy, dx))continue;
            if (visited[dy][dx])continue;

            visited[dy][dx] = true;
            visited_global[dy][dx] = true;
            mq.push({ dy,dx });
        }
    }

}
//queue에 담긴 시작점 돌리기
void run0() {
    int y, x;
    while (!start_queue.empty()) {
        y = start_queue.front().first;
        x = start_queue.front().second;
        start_queue.pop();

        run(y, x);
    }
}
void init() {
    int tem;
    int a, b;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tem;
            arr[i][j] = tem;
        }
    }

    for (int i = 1; i <= k; i++) { //시작점들 주어짐
        cin >> b >> a;
        start_queue.push({ a,b });
    }

}

int main() {
    init();
    run0();
    cout << count_answer();


    return 0;
}