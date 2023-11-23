#include <iostream>
using namespace std;

int n, m;
int grid[101][101];
bool visited[101][101] = {};

int dir_x[2] = {0, 1};
int dir_y[2] = {1, 0};

bool inrange(int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

bool cango(int x, int y) {
    return inrange(x, y) && !visited[x][y] && grid[y][x] == 1;
}

bool run(int x, int y) {
    if (x == m - 1 && y == n - 1) return true; 
    visited[x][y] = true;

    for (int i = 0; i < 2; i++) {
        int dx = x + dir_x[i];
        int dy = y + dir_y[i];
        if (cango(dx, dy) && run(dx, dy)) {
            return true;
        }
    }
    return false;
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
}

int main() {
    init();
    cout << (run(0, 0) ? 1 : 0);
    return 0;
}