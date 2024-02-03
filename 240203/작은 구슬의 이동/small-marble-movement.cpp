#include <iostream>
#include <vector>

using namespace std;

//var 
int dir_x[4]= {0, 1, 0, -1};
int dir_y[4]= {1, 0, -1, 0};

int r, c;
char d;
int d_int;
int n; // 2 50
int t; // 1 100

void run() {
    int tx, ty;
    tx = c - 1;
    ty = r - 1;
    int dx, dy;
    int td = d_int;
    for(int i = 0; i < t; i++) {
        dx = tx + dir_x[td];
        dy = ty + dir_y[td];

        if(dy < 0 || dx < 0 || dy >= n || dx >= n) {
            td = (td + 2) % 4;
        } else {
            tx = dx;
            ty = dy;
        }
    }
    cout << ty + 1 << " " << tx + 1; 
}
void init() {
    cin >> n >> t;
    cin >> r >> c >> d;
    switch (d) {
        case 'U':
            d_int = 0;
            break;
        case 'D':
            d_int = 2;
            break;
        case 'R':
            d_int = 3;
            break;
        case 'L':
            d_int = 1;
            break;
    }
}

int main() {
    init();
    run();
    return 0;
}