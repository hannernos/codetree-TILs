#include <iostream>

using namespace std;


//var
int N;

//func
int y,x;
int dir_x[4] = {-1,0,0,1};
int dir_y[4] = {0,-1,1,0};
int table[101][101];

bool cango(int dx,int dy){
    bool ret = true;
    // if(dx<0||dx>100||dy<0||dx>100)
    //     ret = false;
    return ret;
}
int ans;
int cnt;
bool endflag;

void mv(int dir_n,int cnt_mv){

    for(int i=0;i<cnt_mv;i++){
        y = y + dir_y[dir_n];
        x = x + dir_x[dir_n];
        cnt++;

        if(y == 0 && x == 0){
            ans = cnt;
            endflag = true;
        }
        
    }
}

void run(char a,int b){
    int dir_n;
    int dx,dy;

    switch(a){
        case 'W':
            dir_n = 0;
            break;
        case 'S':
            dir_n = 1;
            break;
        case 'N':
            dir_n = 2;
            break;
        case 'E':
            dir_n = 3;
            break;
        default:
            break;
    }
    // if(cango(x + b*dir_x[dir_n],y + b*dir_y[dir_n])){
    //    y = y + b*dir_y[dir_n];
    //    x = x + b*dir_x[dir_n];
    //    cnt = cnt + b;
    mv(dir_n,b);


    // cout<<"x : "<<x<<" , y : "<<y<<endl;
    

    // if (y == 0 && x == 0 ){
    //     ans = cnt;
    //     endflag = true;
    // }
}

void init(){
    char a;
    int b;
    x = 0;
    y = 0;
    ans = -1;
    cnt = 0;
    endflag = false;

    cin>>N;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        if(!endflag)
        run(a,b);
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    cout<<ans;

    return 0;
}