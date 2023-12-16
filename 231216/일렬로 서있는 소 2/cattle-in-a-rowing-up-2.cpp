#include <iostream>



using namespace std;

//var
int N;
int arr[101];
int cnt;
//func

void run2(int a,int b,int c){
    if(a>b){
        return;
    }
    if(b>c){
        return;
    }
    if(a>c){
        return;
    }

    cnt++;
    return;
}

void run(){
    //완전탐색
    //3중 for문 돌리면서 비교하고 카운트
    int a, b, c;
    for(int i=0;i<N;i++){
        a = arr[i];
        for(int j=i+1;j<N;j++){
            b = arr[j];
            for(int k=j+1;k<N;k++){
                c = arr[k];
                run2(a,b,c);
            }
        }
    }
    cout<<cnt;

}

void init(){

    int tem;
    cnt = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tem;
        arr[i] = tem;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();

    return 0;
}