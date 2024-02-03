/*
가다가 박음 방향전환 1초

*/
#include <iostream>
#include <vector>

using namespace std;

//var 
int dir_x[4]= {0,1,0,-1};
int dir_y[4]= {1,0,-1,0};

int r,c;
char d;
int d_int;
int n; // 2 50
int t; // 1 100

void run(){
    int tx,ty;
    tx = c;
    ty = r;
    int dx,dy;
    int td = d_int;
    for(int i=0;i<t;i++){
        dx = tx + dir_x[td];
        dy = ty + dir_y[td];

        if (dy<1||dx<1||dy>n||dx>n){
            td = (td+2)%4;
        }else{
            tx = dx;
            ty = dy;
        }
    }
    cout<<ty<<" "<<td;
}

void init(){
    cin >> n>>t;
    cin>>r>>c>>d;
// int dir_x[4]= {0,1,0,-1};
// int dir_y[4]= {1,0,-1,0};
    switch (d){
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
    // 여기에 코드를 작성해주세요.
    init();
    run();
    return 0;
}