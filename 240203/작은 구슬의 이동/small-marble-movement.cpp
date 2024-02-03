#include <iostream>

using namespace std;

//var 
int n,t;
int r,c,d;

int dir_y[4] = {1,0,-1,0};
int dir_x[4] = {0,1,0,-1};

//func

void run(){

    int ty = r;
    int tx = c;

    int dy,dx;

    int td = d;
    for(int i=0;i<t;i++){
        dy = ty + dir_y[td];
        dx = tx + dir_x[td];
        if(dy<1||dx<1||dy>n||dx>n){
            td = (td + 2 ) % 4;
        }else{
            ty = dy;
            tx = dx;
        }

    }

    cout<<ty<<" "<<dx;
}
void init(){
    cin>>n>>t;
    cin>>r>>c;//r행 c열
    char cd;
    cin>>cd;
    switch(cd){
        case 'U':
            d = 0;
            break;
        case 'D':
            d = 2;
            break;
        case 'R':
            d = 1;
            break;
        case 'L':
            d = 3;
            break;
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    return 0;
}