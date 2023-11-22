/*
1 ~ K   1 ~ 4
N번 반복    1 ~ 8

*/
#include <iostream>


using namespace std;



//var

int K,N;
int arr[100];

//func
void run(int a,int b){
    arr[a]=b;
    a++;
    if(a>N){
        for(int i=1;i<a;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=K;i++){
        run(a,i);
    }
    
    return;
}
void init(){
    cin>>K>>N;
}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    for(int i=1;i<=K;i++){
        arr[1]=i;
        run(1,i);
    }
    return 0;
}