#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// var
int N, M;  
int arr[51][51];
bool visited[51][51];
int k;

int dir_y[4] = {-1, 0, 1, 0};
int dir_x[4] = {0, 1, 0, -1};

//func
bool cango(int dy, int dx) {
    if (dy < 0 || dx < 0 || dy >= N || dx >= M) {
        return false;
    }
    if (arr[dy][dx] <= k || visited[dy][dx]) {
        return false;
    }
    return true;
}

void run(int y, int x) {
    visited[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int dy = y + dir_y[i];
        int dx = x + dir_x[i];

        if (cango(dy, dx)) {
            run(dy, dx);
        }
    }
}

int countSafeAreas() {
    int safeAreas = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cango(i, j)) {
                run(i, j);
                safeAreas++;
            }
        }
    }
    return safeAreas;
}

int main() {
    cin >> N >> M;
    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            maxHeight = max(maxHeight, arr[i][j]);
        }
    }

    int maxSafeAreas = 0, kAtMax = 0;
    for (int i = 1; i <= maxHeight; i++) {
        k = i;
        int currentSafeAreas = countSafeAreas();
        if (currentSafeAreas >= maxSafeAreas) {
            maxSafeAreas = currentSafeAreas;
            kAtMax = i;
        }
    }

    cout << kAtMax << " " << maxSafeAreas << endl;
    
    return 0;
}