#include<iostream>
#include<vector>

using namespace std;

void init();
void run(int y, int x);
void print();

//var
int dir;
int dir_x[2] = { 0,1 };
int dir_y[2] = { 1,0 };
bool ans;

int n, m;

int arr[213][213];

int main() {

    init();
    run(0, 0);
    print();

    return 0;
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    ans = false;
}

void run(int y, int x) {
    int dx, dy;

    if (dx == n - 1 && dy == n - 1) {
        ans = true;
        return;
    }

    for (int i = 0; i < 2; i++) {
        dx = x + dir_x[i];
        dy = y + dir_y[i];

        if (dx < 0 || dx >= n || dy < 0 || dy >= n || arr[dy][dx] == 1) {
            continue;
        }

        run(dy, dx);

    }


}

void print() {
    if (ans) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}