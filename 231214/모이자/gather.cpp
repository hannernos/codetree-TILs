#include <iostream>

using namespace std;

//var

int n;
int arr[101];

//func
int abs(int a){
    if(a<0){
        a = -a;
    }
    return a;
}

void init(){
    int tem;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> tem;
        arr[i] = tem;
    }
}

int run2(int p){
    //해당 지점을 기점으로 한 이동거리의 합 구하기
    int tem_len = 0;
    for(int i = 0;i < n;i++){
        tem_len += arr[i]*(abs(p-i));
    }
    return tem_len;
}

void run(){
    int min_len = 2e9;
    int tem;
    for(int i=0;i<n;i++){
        //각 지점 거리 구하기
        tem = run2(i);
        if(min_len>tem){
            min_len = tem;
        }
    }
    cout<<min_len;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    return 0;
}