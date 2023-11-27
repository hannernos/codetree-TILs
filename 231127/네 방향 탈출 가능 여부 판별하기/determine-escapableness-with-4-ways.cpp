#include <iostream>
#include<queue>

using namespace std;

//var
int n, m;
int arr[101][101];
bool visited[101][101] = {false};

int dir_y[5] = {0,-1,0,1,0};
int dir_x[5] = {0,0,1,0,-1};

int des_x;
int des_y;

int answer = 0;

//func
bool isanswer(int y,int x) {
    if (y == des_y && x == des_x) {
        return true;
    }
    return false;
}

bool cango(int y,int x) {
    if (y<1 || x<1 || y>n || x>m)return false;
    if (arr[y][x] == 0)return false;
    if (visited[y][x]) return false;
    return true;
}
void run(int py, int px) {


    //int x, y;
    int dx, dy;
    int y, x;
    queue<pair<int,int>> mq;
    mq.push({ py, px });

    while (!mq.empty()) {

        y = mq.front().first;
        x = mq.front().second;
        mq.pop();


        for (int i = 1; i <= 4; i++) {

            dx = x + dir_x[i];
            dy = y + dir_y[i];

            if (isanswer(dy, dx)) {
                answer = 1;
                return;
            }

            if (!cango(dy, dx)) {
                continue;
            }

            visited[dy][dx] = true;
            mq.push({ dy,dx });

        
        }
    }
    


}
void init() {
    int tem;
    cin >> n >> m;
    des_x = m;
    des_y = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
            cin >> tem;
            arr[i][j] = tem;

        }
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run(1,1);//좌측 상단에서 시작
    cout << answer;
    return 0;
}