#include <iostream>

using namespace std;

//var

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int dir_num;

int x,y;
int nx,ny;

void init(){
    x=0;y=0;
    dir_num=0;

   //int N;
    //cin>>N;
    char a,b;
    cin>>a>>b;
    
    if(a == 'L'){// 왼쪽 90도 회전
        dir_num = (dir_num - 1 +4 )%4;
    }else{//오른쪽 90도 회전

        dir_num = (dir_num + 1 +4 )%4;
    }

    x += dx[dir_num];
    y += dy[dir_num];

    cout<<x<<" "<<y;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}