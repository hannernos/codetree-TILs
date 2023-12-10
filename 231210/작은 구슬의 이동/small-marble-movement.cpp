#include <iostream>
#include <map>
using namespace std;

int n, t, r, c;
char d;
map<char, pair<int, int>> mm = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'R', {0, 1}},
    {'L', {0, -1}}
};

char dir_conflict(char dir) {
    switch (dir) {
        case 'U': return 'D';
        case 'D': return 'U';
        case 'R': return 'L';
        case 'L': return 'R';
        default: return ' ';
    }
}

void bead() {
    int actualTime = 0; 
    while (actualTime < t) {
        int dy = r + mm[d].first;
        int dx = c + mm[d].second;

        if (dy < 1 || dx < 1 || dy > n || dx > n) {
            d = dir_conflict(d);
            actualTime++; 
        } else {
            r = dy;
            c = dx;
            actualTime++;
        }
    }
}

void init() {
    cin >> n >> t;
    cin >> r >> c >> d;
}

int main() {
    init();
    bead();
    cout << r << ' ' << c;
    return 0;
}