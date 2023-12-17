#include <iostream>

using namespace std;
//var 
int N;
int arr[21][21];
int max_ans;
int max_num;
//func

void run2(int a,int b){
    int tem=0;

    for(int i=0;i<3;i++){
        tem+=arr[a][b+i];
    }

    if(max_num<tem){max_num = tem;
    }
}

void run(){

    for(int i=0;i < N;i++){
        for(int j=0;j < N-2;j++){
            run2(i,j);
        }
        if(max_num == 3){break;}
    }
}

void init(){
    int tem;
    max_ans = 0;
    max_num = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tem;
            arr[i][j] = tem;
        }
    }
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();

    cout<<max_num;
    return 0;
}