#include <iostream>


using namespace std;
void init();
void run();
void run2(char a);


void print();

//var
string input;
int len;

//dir
int y, x;

int dir_x[4] = { 1,0,-1,0 };//우 하 좌 상
int dir_y[4] = { 0,-1,0,1 };

int dir;
bool flag;

//main
int main() {
    init();
    run();
    return 0;
}

void init() {
    cin >> input;
    len = input.length();
    flag = false;

    y = 0; x = 0;
    dir = 3;

}
void run() {
    char a;
    for (int i = 0; i < len; i++) {
        a = input.at(i);
        run2(a);
        if (flag) {
            cout << i + 1;
            break;
        }
    }

    if (!flag) {
        cout << -1;
    }
}

void run2(char a) {


    switch (a) {
    case 'L':
        dir = (dir - 1 + 4) % 4;
        break;
    case 'R':
        dir = (dir + 1) % 4;
        break;

    default:
        //F
        y = y + dir_y[dir];
        x = x + dir_x[dir];

        if (y == 0 && x == 0) {
            flag = true;
        }
        //print();
        break;

    }


}

void print() {
    cout << "y : " << y << "x: " << x << endl;
}