#include <iostream>

using namespace std;

void init();
void run();
bool check(int py,int px);
void print();
//var
int n;
int y,x;
// R U L D , 아래가 위로
int dir;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, -1, 0, 1};

int arr[102][102];

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    print();
    return 0;
}

//func
void init(){
    cin>>n;
}
void run(){
    int cnt = 1;
    dir = 0;

    y = (n / 2) + 1;
    x = (n / 2) + 1;

    for(int i=0;i<(n*n);i++){

        arr[y][x] = cnt;

        if(!check(y + dir_y[dir],x + dir_x[dir])){
            dir = (dir + 1) % 4;    
        }else{}

        y = y + dir_y[dir];
        x = x + dir_x[dir];
        cnt++;
    }
}

bool check(int py, int px){
    if(py<1||px<1||py>n||px>n||arr[py][px]>0){
        return false;
    }
    return true;
}

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<< " " ;
        }cout<<"\n";
    }cout<<"\n";
}