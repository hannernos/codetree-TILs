#include <iostream>

using namespace std;

//var
int arr[101][101];
int n;

int dir_y[5]={0, -1,1,0,0};
int dir_x[5]={0, 0,0,-1,1};

int cnt;
//func

void check(int py, int px){
    int local_cnt=0;
    int dy,dx;
    //격자 안에 존재하는지 점검하고 1 3개 이상인지 check
    for(int i=1;i<=4;i++){
        dy = py + dir_y[i];
        dx = px + dir_x[i];

        if(dy<1||dx<1||dy>n||dx>n){
            continue;
        }

        if(arr[dy][dx]==1){
            local_cnt++;
        }


    }

    if(local_cnt>=3){
        cnt++;
    }


}

void run(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            check(i,j);
        }
    }

}
void init(){

    int tem;
    cnt = 0;

    cin>>n;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){
            cin >> tem;
            arr[i][j] = tem;

        }
    }


}


int main() {
    init();
    run();
    cout<<cnt;
    return 0;
}